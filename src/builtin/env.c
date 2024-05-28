/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:42:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/05/24 13:43:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	env(char **args, t_env *minienv)
{
	t_env	*node;

	if (args[0] && args[1])
	{
		if (args[1][0] == '-')
			return (print_error_msg(args[1], "Don't take option", ERROR), 2);
		print_error_msg(args[1], "No such file or directory", ERROR);
		return (127);
	}
	node = minienv;
	if (!node)
	{
		print_error_msg("env", "No such file or directory", ERROR);
		return (127);
	}
	while (node)
	{
		if (ft_strchr(node->data, '='))
		{
			ft_putstr_fd(node->data, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
		node = node->next;
	}
	return (0);
}