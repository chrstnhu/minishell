/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_value_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:55:23 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:25:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**get_args(char *wildcard_label)
{
	char	**args;

	args = malloc(sizeof(char *) * 11);
	args[0] = "find";
	args[1] = ".";
	args[2] = "-maxdepth";
	args[3] = "1";
	args[4] = "-name";
	if (!ft_strcmp(wildcard_label, "*"))
		args[5] = "[!.]*";
	else
		args[5] = wildcard_label;
	args[6] = "-exec";
	args[7] = "basename";
	args[8] = "{}";
	args[9] = ";";
	args[10] = NULL;
	return (args);
}

static void	execute_find(char *wildcard_label, int pipe_fd[2], t_env *minienv)
{
	char	**env;

	rl_clear_history();
	env = minienv_to_env(minienv);
	free_minienv(&minienv);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (execve("/usr/bin/find", get_args(wildcard_label), env) == -1)
		exit(EXIT_FAILURE);
}

static void	remove_new_line(char *wildcard_value)
{
	while (*wildcard_value)
	{
		if (*wildcard_value == '\n' && wildcard_value[1])
			*wildcard_value = ' ';
		else if (*wildcard_value == '\n')
			*wildcard_value = '\0';
		wildcard_value++;
	}
}

char	*get_wildcard_value(char *wildcard_label, char **input, t_env *minienv)
{
	int		child_pid;
	int		pipe_fd[2];
	char	wildcard_value[PATH_MAX];

	pipe(pipe_fd);
	child_pid = fork();
	if (child_pid == -1)
		print_error_msg("fork", "wildcard", PERROR);
	if (child_pid == 0)
	{
		free(*input);
		execute_find(wildcard_label, pipe_fd, minienv);
	}
	free(wildcard_label);
	close(pipe_fd[1]);
	waitpid(child_pid, NULL, 0);
	ft_bzero(wildcard_value, sizeof(wildcard_value));
	read(pipe_fd[0], wildcard_value, sizeof(wildcard_value));
	close(pipe_fd[0]);
	remove_new_line(wildcard_value);
	return (ft_strdup(wildcard_value));
}
