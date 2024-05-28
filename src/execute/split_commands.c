/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:41:12 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/16 13:24:13 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	replace_pipe(char *str, char limiter)
{
	while (*str && *str != limiter)
		str++;
	if (*str)
		str++;
	while (*str && *str != limiter)
	{
		if (*str == '|')
			*str = -1;
		str++;
	}
	if (*str)
		str++;
	if (*str)
		replace_pipe(str, limiter);
}

static void	restore_pipe(char **args)
{
	char	*str;

	while (*args)
	{
		str = *args;
		while (*str)
		{
			if (*str == -1)
				*str = '|';
			str++;
		}
		args++;
	}
	return ;
}

char	**split_commands(char *input)
{
	char	**commands;

	replace_pipe(input, '"');
	replace_pipe(input, '\'');
	commands = ft_split(input, '|');
	restore_pipe(commands);
	return (commands);
}
