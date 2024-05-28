/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:53:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/05/24 17:11:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(char *command)
{
	if (!command)
		return (0);
	if (ft_strncmp(command, "echo", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "cd", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "pwd", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "export", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "unset", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "env", ft_strlen(command) + 1) == 0)
		return (1);
	if (ft_strncmp(command, "exit", ft_strlen(command) + 1) == 0)
		return (1);
	return (0);
}

int	execute_builtin(char **args, t_env **minienv)
{
	char	*command;

	command = args[0];
	if (ft_strncmp(command, "echo", ft_strlen(command) + 1) == 0)
		return (echo(args));
	if (ft_strncmp(command, "cd", ft_strlen(command) + 1) == 0)
		return (cd(args, *minienv));
	if (ft_strncmp(command, "pwd", ft_strlen(command) + 1) == 0)
		return (pwd(*minienv));
	if (ft_strncmp(command, "export", ft_strlen(command) + 1) == 0)
		return (export(args, minienv));
	if (ft_strncmp(command, "unset", ft_strlen(command) + 1) == 0)
		return (unset(args, minienv));
	if (ft_strncmp(command, "env", ft_strlen(command)+ 1) == 0)
		return (env(args, *minienv));
	if (ft_strncmp(command, "exit", ft_strlen(command) + 1) == 0)
		return (builtin_exit(args, minienv));
	else
		return (EXIT_FAILURE);
}
