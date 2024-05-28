/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_multi_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:54:33 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:40:57 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	handle_redirects(char *command, char **commands, t_env **minienv)
{
	char	redirect;

	redirect = get_next_redirect(command);
	while (redirect)
	{
		if ((redirect == '<' && !redirect_input(command))
			|| (redirect == '>' && !redirect_output(command)))
		{
			rl_clear_history();
			free_minienv(minienv);
			free_array(commands);
			close_all_fds();
			exit(EXIT_FAILURE);
		}
		if (redirect < 0)
			redirect_heredoc(command, redirect);
		redirect = get_next_redirect(command);
	}
}

static void	execute_forked_command(char *command, char **commands,
		t_env **minienv)
{
	char	**args;
	int		exit_status;

	close_extra_fds();
	args = split_args(command, minienv);
	free_array(commands);
	if (is_builtin(args[0]))
	{
		exit_status = execute_builtin(args, minienv);
		free_array(args);
		free_minienv(minienv);
		rl_clear_history();
		exit(exit_status);
	}
	else
		execute_external(args, *minienv);
}

static void	restore_fds(int fds[2])
{
	redirect_fd(fds[0], STDIN_FILENO);
	redirect_fd(fds[1], STDOUT_FILENO);
}

int	execute_multi_commands(char **commands, t_env **minienv)
{
	int	fds[2];
	int	*children_pid;
	int	i;

	fds[0] = dup(STDIN_FILENO);
	fds[1] = dup(STDOUT_FILENO);
	children_pid = init_children_pid(commands);
	i = 0;
	while (commands[i])
	{
		handle_pipe(fds[1], commands[i], commands);
		children_pid[i] = fork();
		define_execute_signal(children_pid[i]);
		if (children_pid[i] == -1)
			print_error_msg("fork", commands[i], PERROR);
		else if (children_pid[i] == 0)
		{
			free(children_pid);
			handle_redirects(commands[i], commands, minienv);
			execute_forked_command(commands[i], commands, minienv);
		}
		i++;
	}
	restore_fds(fds);
	return (wait_children(children_pid));
}
