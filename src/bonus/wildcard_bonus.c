/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:24:42 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/23 15:24:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_wildcard_label(char c)
{
	return (ft_isalnum(c) || c == '*' || c == '.' || c == '/');
}

static char	*get_wildcard_label_pos(char *str)
{
	char	*start;

	start = str;
	while (*str)
	{
		str += skip_quote(str);
		if (*str == '*')
		{
			while ((str - 1) >= start && is_wildcard_label(*(str - 1)))
				str--;
			return (str);
		}
		str++;
	}
	return (NULL);
}

static char	*get_wildcard_label(char *wildcard_label_pos)
{
	int	label_size;

	label_size = 0;
	while (is_wildcard_label(wildcard_label_pos[label_size]))
		label_size++;
	return (ft_substr(wildcard_label_pos, 0, label_size));
}

static void	update_input(char **input, char *wildcard_value, char *second_part)
{
	char	*first_part;
	char	*updated_input;

	if (!*input[0] && !wildcard_value)
		first_part = ft_strdup("");
	else if (!*input[0] && wildcard_value)
		first_part = ft_strdup(wildcard_value);
	else if (!wildcard_value)
		first_part = ft_strdup(*input);
	else
		first_part = ft_strjoin(*input, wildcard_value);
	updated_input = ft_strjoin(first_part, second_part);
	free(first_part);
	free(*input);
	*input = updated_input;
}

void	expand_wildcard(char *search, char **input, t_env *minienv)
{
	char	*wildcard_label_pos;
	char	*wildcard_label;
	int		label_size;
	char	*wildcard_value;
	int		next_search_index;

	wildcard_label_pos = get_wildcard_label_pos(search);
	if (!wildcard_label_pos)
		return ;
	wildcard_label = get_wildcard_label(wildcard_label_pos);
	label_size = ft_strlen(wildcard_label);
	wildcard_value = get_wildcard_value(wildcard_label, input, minienv);
	if (*wildcard_value)
	{
		*wildcard_label_pos = '\0';
		next_search_index = ft_strlen(*input);
		update_input(input, wildcard_value, &wildcard_label_pos[label_size]);
		next_search_index += ft_strlen(wildcard_value);
		expand_wildcard(&(*input)[next_search_index], input, minienv);
	}
	else
		expand_wildcard(&wildcard_label_pos[label_size], input, minienv);
	free(wildcard_value);
}
