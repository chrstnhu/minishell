/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:54:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/05/24 13:44:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*find_exit_status_position(char *input)
{
	while (*input)
	{
		if (*input == '\'')
		{
			input++;
			while (*input && *input != '\'')
				input++;
		}
		if (*input == '\"')
		{
			input++;
			while (*input && *input != '\"')
			{
				if (*input == '$' && input[1] == '?')
					return (input);
				input++;
			}
		}
		if (*input == '$' && input[1] == '?')
			return (input);
		input++;
	}
	return (NULL);
}

static void	update_input(char **input, char *exit_code, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	first_part = ft_strjoin(*input, exit_code);
	updated_input = ft_strjoin(first_part, second_part);
	free(*input);
	free(first_part);
	*input = updated_input;
}

void	expand_exit_status(char **input, int exit_status)
{
	char	*exit_status_pos;
	char	*exit_status_str;

	exit_status_pos = find_exit_status_position(*input);
	if (exit_status_pos)
	{
		*exit_status_pos = '\0';
		exit_status_str = ft_itoa(exit_status);
		update_input(input, exit_status_str, (exit_status_pos + 2));
		free(exit_status_str);
		expand_exit_status(input, exit_status);
	}
}
