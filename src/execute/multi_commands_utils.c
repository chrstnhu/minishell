/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:41:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/05/23 15:41:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (*arr)
	{
		len++;
		arr++;
	}
	return (len);
}

int	*init_children_pid(char **commands)
{
	int		*children_pid;
	size_t	size;

	size = sizeof(int) * (arr_len(commands) + 1);
	children_pid = malloc(size);
	if (!children_pid)
		return (NULL);
	ft_bzero(children_pid, size);
	return (children_pid);
}

void	handle_pipe(int fd_out, char *current_command, char **commands)
{
	int			is_first_command;
	int			has_next_command;
	char		*last_command;
	static int	pipe_fds[2];

	last_command = commands[arr_len(commands) - 1];
	is_first_command = (current_command == commands[0]);
	has_next_command = (current_command != last_command);
	if (!is_first_command)
		redirect_fd(pipe_fds[0], STDIN_FILENO);
	if (has_next_command)
	{
		if (pipe(pipe_fds) == -1)
			print_error_msg("pipe", current_command, PERROR);
		redirect_fd(pipe_fds[1], STDOUT_FILENO);
	}
	else
		redirect_fd(fd_out, STDOUT_FILENO);
}
