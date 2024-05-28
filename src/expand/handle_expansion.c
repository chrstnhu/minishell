/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:07:21 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/17 19:18:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_expansion(char **input, t_env *minienv, int exit_status)
{
	expand_exit_status(input, exit_status);
	expand_variable(input, minienv);
}
