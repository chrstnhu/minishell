/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:36:34 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/24 14:41:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	replace_spaces(char *str, char limiter)
{
	while (*str && *str != limiter)
		str++;
	if (*str)
		str++;
	while (*str && *str != limiter)
	{
		if (*str == ' ')
			*str = -1;
		str++;
	}
	if (*str)
		str++;
	if (*str)
		replace_spaces(str, limiter);
}

static void	restore_space(char **args)
{
	char	*str;

	while (*args)
	{
		str = *args;
		while (*str)
		{
			if (*str == -1)
				*str = ' ';
			if (*str == -2)
				*str = '\'';
			if (*str == -3)
				*str = '"';
			str++;
		}
		args++;
	}
	return ;
}

static void	replace_quote_by_null(char **exec_args)
{
	int	i;

	i = 0;
	while (exec_args[i])
	{
		if (exec_args[i][0] == '"' && exec_args[i][1] == '"')
		{
			exec_args[i][0] = '\'';
			exec_args[i][1] = '\'';
		}
		if (exec_args[i][0] == '\'' && i != 0
			&& exec_args[i][0] == exec_args[i][1] && exec_args[i][2] == '\0')
			exec_args[i][0] = '\0';
		i++;
	}
}

static void	replace_space_and_quote(char *command)
{
	replace_spaces(command, '\'');
	replace_single_quotes(command, '\'');
	replace_spaces(command, '"');
	replace_double_quotes(command, '"');
}

char	**split_args(char *command, t_env **minienv)
{
	char	**exec_args;
	char	*command_copy;
	int		i;

	i = 1;
	replace_tabs_with_spaces(command);
	if (!contains_quote_mark(command))
	{
		command_copy = find_and_replace_tilde(command, *minienv);
		exec_args = ft_split(command_copy, ' ');
		return (free(command_copy), exec_args);
	}
	replace_space_and_quote(command);
	exec_args = ft_split(command, ' ');
	restore_space(exec_args);
	replace_quote_by_null(exec_args);
	if (contains_alpha(exec_args[0]) || ((exec_args[0][0] == '\''
			|| exec_args[0][0] == '"') && exec_args[0][1] == ' '))
		remove_quote(exec_args[0]);
	while (exec_args[i])
	{
		remove_quote(exec_args[i]);
		i++;
	}
	return (exec_args);
}
