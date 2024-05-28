/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:52:17 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:32:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	get_next_redirect(char *str)
{
	while (*str)
	{
		str += skip_quote(str);
		if (*str == '<' || *str == '>' || *str < 0)
			return (*str);
		str++;
	}
	return (0);
}

char	*get_redirect_position(char *str, char redirect_char)
{
	while (*str)
	{
		str += skip_quote(str);
		if (*str == redirect_char)
			return (str);
		str++;
	}
	return (NULL);
}

int	redirect_input(char *command)
{
	char	*input_redirect;
	char	*file_name;
	int		fd;

	input_redirect = get_redirect_position(command, '<');
	if (!input_redirect)
		return (SUCCESS);
	file_name = get_label_name(input_redirect);
	fd = open(file_name, O_RDONLY, FD_CLOEXEC);
	if (fd == -1)
	{
		print_error_msg("open", file_name, PERROR);
		free(file_name);
		return (FAILED);
	}
	else
		redirect_fd(fd, STDIN_FILENO);
	free(file_name);
	return (SUCCESS);
}

int	redirect_output(char *command)
{
	char	*output_redirect;
	char	*file_name;
	int		fd;
	int		open_flags;

	output_redirect = get_redirect_position(command, '>');
	if (!output_redirect)
		return (SUCCESS);
	if (output_redirect[1] == '>')
		open_flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		open_flags = O_WRONLY | O_CREAT | O_TRUNC;
	file_name = get_label_name(output_redirect);
	fd = open(file_name, open_flags, 0644);
	if (fd == -1)
	{
		print_error_msg("open", file_name, PERROR);
		free(file_name);
		return (FAILED);
	}
	else
		redirect_fd(fd, STDOUT_FILENO);
	free(file_name);
	return (SUCCESS);
}

void	redirect_heredoc(char *command, int heredoc_nbr)
{
	char	*file_name;
	int		tmp_file_fd;
	char	*heredoc_pos;
	int		len;

	file_name = tmp_filename(heredoc_nbr);
	tmp_file_fd = open(file_name, O_RDONLY);
	if (tmp_file_fd == -1)
	{
		print_error_msg("open", file_name, PERROR);
		free(file_name);
		return ;
	}
	free(file_name);
	redirect_fd(tmp_file_fd, STDIN_FILENO);
	heredoc_pos = get_redirect_position(command, heredoc_nbr);
	len = ft_strlen(heredoc_pos + 1) + 1;
	ft_memmove(heredoc_pos, heredoc_pos + 1, len);
}
