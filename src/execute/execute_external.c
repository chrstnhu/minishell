/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:12:17 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:41:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	external_exit(char **args, t_env *minienv, int exit_status)
{
	if (exit_status == 126)
		print_error_msg(args[0], "Is a directory", ERROR);
	if (exit_status == 127)
		print_error_msg(args[0], "command not found", ERROR);
	rl_clear_history();
	free_minienv(&minienv);
	free_array(args);
	close_all_fds();
	exit(exit_status);
}

static int	is_folder(char *command)
{
	struct stat	statbuf;

	if (stat(command, &statbuf) != 0)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		if (*command == '.')
			command++;
		if (*command == '.')
			command++;
		if (*command == '/')
			return (1);
	}
	return (0);
}

static void	handle_execve_errors(char **args, char *path, char **env)
{
	int	exit_status;

	exit_status = EXIT_FAILURE;
	print_error_msg("execve", args[0], PERROR);
	if (access(path, F_OK) != 0)
		exit_status = 127;
	else if (access(path, X_OK) != 0)
		exit_status = 126;
	rl_clear_history();
	free_array(args);
	free_array(env);
	free(path);
	exit(exit_status);
}

int	execute_external(char **args, t_env *minienv)
{
	char	*path;
	char	*command;
	char	**env;

	command = args[0];
	if (!command)
		external_exit(args, minienv, 0);
	if (is_empty(args[0]))
		external_exit(&args[0], minienv, 127);
	if (is_folder(command))
		external_exit(args, minienv, 126);
	path = get_path(command, minienv);
	if (path == NULL && minienv_value("PATH", minienv))
		external_exit(args, minienv, 127);
	else if (path == NULL)
		path = ft_strdup(command);
	rl_clear_history();
	close_extra_fds();
	env = minienv_to_env(minienv);
	free_minienv(&minienv);
	if (execve(path, args, env) == -1)
		handle_execve_errors(args, path, env);
	exit(EXIT_SUCCESS);
}
