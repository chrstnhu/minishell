/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:23:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/05/24 13:44:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static size_t	calculate_command_len(char *command, t_env *minienv)
{
	char	*tilde_pos;
	size_t	new_command_len;
	size_t	home_len;

	tilde_pos = command;
	new_command_len = 0;
	home_len = ft_strlen(minienv_value("__HOME", minienv));
	while (*tilde_pos)
	{
		if (*tilde_pos == '~')
			new_command_len += home_len;
		else
			new_command_len++;
		tilde_pos++;
	}
	return (new_command_len);
}

static void	expand_tilde_path(char *new_command_ptr, char *command_ptr,
	char *expanded_path, t_env *minienv)
{
	size_t	home_len;
	int		escape_flag;

	home_len = ft_strlen(minienv_value("__HOME", minienv));
	escape_flag = 0;
	while (*command_ptr)
	{
		if (*command_ptr == '\\' && !escape_flag)
		{
			escape_flag = 1;
			command_ptr++;
		}
		else if (*command_ptr == '~' && !escape_flag && expanded_path != NULL)
		{
			ft_memcpy(new_command_ptr, expanded_path, home_len);
			new_command_ptr += home_len;
			command_ptr++;
		}
		else
		{
			*new_command_ptr++ = *command_ptr++;
			escape_flag = 0;
		}
	}
	*new_command_ptr = '\0';
}

char	*find_and_replace_tilde(char *command, t_env *minienv)
{
	char	*command_ptr;
	char	*new_command;
	char	*new_command_ptr;
	char	*expanded_path;
	size_t	new_command_len;

	new_command_len = calculate_command_len(command, minienv);
	new_command = malloc(new_command_len + 1);
	if (!new_command)
		return (command);
	new_command_ptr = new_command;
	command_ptr = command;
	expanded_path = minienv_value("__HOME", minienv);
	expand_tilde_path(new_command_ptr, command_ptr, expanded_path, minienv);
	return (new_command);
}
