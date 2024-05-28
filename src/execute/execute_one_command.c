/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_one_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:13:50 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:40:23 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	handle_put_redirect(char *command, int fds[2], int put)
{
	if (put == 0)
	{
		if (fds[0] == -1)
			fds[0] = dup(STDIN_FILENO);
		if (!redirect_input(command))
		{
			redirect_fd(fds[0], STDIN_FILENO);
			return (FAILED);
		}
	}
	else if (put == 1)
	{
		if (fds[1] == -1)
			fds[1] = dup(STDOUT_FILENO);
		if (!redirect_output(command))
		{
			redirect_fd(fds[1], STDOUT_FILENO);
			return (FAILED);
		}
	}
	return (SUCCESS);
}

static int	handle_redirects(char *command, int fds[2])
{
	char	redirect;

	fds[0] = -1;
	fds[1] = -1;
	redirect = get_next_redirect(command);
	while (redirect)
	{
		if (redirect == '<' && !handle_put_redirect(command, fds, 0))
			return (FAILED);
		if (redirect == '>' && !handle_put_redirect(command, fds, 1))
			return (FAILED);
		if (redirect < 0)
		{
			if (fds[0] == -1)
				fds[0] = dup(STDIN_FILENO);
			redirect_heredoc(command, redirect);
		}
		redirect = get_next_redirect(command);
	}
	return (SUCCESS);
}

static void	restore_fds(int fds[2])
{
	if (fds[0] != -1)
		redirect_fd(fds[0], STDIN_FILENO);
	if (fds[1] != -1)
		redirect_fd(fds[1], STDOUT_FILENO);
}

static int	execute_forked_external(char **args, t_env *minienv)
{
	int		child_pid;
	char	*command;

	command = args[0];
	child_pid = fork();
	define_execute_signal(child_pid);
	if (child_pid == -1)
		print_error_msg("fork", command, PERROR);
	else if (child_pid == 0)
		execute_external(args, minienv);
	else
		return (wait_child(child_pid, 1));
	exit(EXIT_FAILURE);
}

int	execute_one_command(char *command, t_env **minienv)
{
	char	**args;
	int		exit_status;
	int		fds[2];

	if (!handle_redirects(command, &fds[0]))
	{
		restore_fds(fds);
		free(command);
		return (EXIT_FAILURE);
	}
	args = split_args(command, minienv);
	free(command);
	if (is_builtin(args[0]))
		exit_status = execute_builtin(args, minienv);
	else
		exit_status = execute_forked_external(args, *minienv);
	free_array(args);
	restore_fds(fds);
	return (exit_status);
}
