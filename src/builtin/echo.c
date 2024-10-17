/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:05:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 16:03:06 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	echo(char **args)
{
	int	i;
	int j;
	int	new_line;

	i = 0;
	j = 2;
	new_line = 1;
	while (args[++i] && ft_strncmp(args[i], "-n", 2) == 0)
	{
		while (args[i][j] == 'n')
			j++;
		if (args[i][j] != '\0')
			break ;
		new_line = 0;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (new_line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
