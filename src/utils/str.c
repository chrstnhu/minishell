/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:04:13 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/24 12:40:42 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	contains_alpha(char *args)
{
	while (*args)
	{
		if (ft_isalpha(*args))
			return (1);
		args++;
	}
	return (0);
}

int	contains_quote_mark(char *str)
{
	if (!str)
		return (0);
	while (str && *str)
	{
		if (*str == '\'' || *str == '"')
			return (1);
		str++;
	}
	return (0);
}

int	is_empty(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	has_pipe(char *str)
{
	while (*str)
	{
		str += skip_quote(str);
		if (*str == '|')
			return (1);
		str++;
	}
	return (0);
}
