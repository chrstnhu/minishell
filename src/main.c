/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:17:52 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 16:43:33 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*prompt_input(t_env *minienv)
{
	char		*input;
	char		*cwd;
	static char	prompt[PATH_MAX];

	cwd = minienv_value("PWD", minienv);
	if (!cwd)
		cwd = "/unknown";
	ft_bzero(prompt, sizeof(prompt));
	ft_strlcat(prompt, "\001\e[0;35m\002\033[1;35m", PATH_MAX);
	ft_strlcat(prompt, cwd, PATH_MAX);
	ft_strlcat(prompt, "$ ", PATH_MAX);
	ft_strlcat(prompt, "\001\e[0m\002", PATH_MAX);
	input = readline(prompt);
	if (!input)
		builtin_exit(NULL, &minienv);
	if (input && *input)
		add_history(input);
	return (input);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

int	minishell(t_env *minienv)
{
	int		exit_status;
	char	*input;
	char	**commands;

	exit_status = EXIT_SUCCESS;
	while (1)
	{
		define_main_signal();
		input = prompt_input(minienv);
		if (has_input_error(input, &exit_status, minienv))
			continue ;
		handle_expansion(&input, minienv, exit_status);
		if (!has_pipe(input))
			exit_status = execute_one_command(input, &minienv);
		else
		{
			commands = split_commands(input);
			free(input);
			exit_status = execute_multi_commands(commands, &minienv);
			free_array(commands);
		}
	}
	rl_clear_history();
	return (exit_status);
}

int	main(int ac, char **av, char **env)
{
	if (av && ac > 1)
	{
		ft_putstr_fd("Minishell can't take arguments.\n", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	return (minishell(init_minienv(env)));
}
