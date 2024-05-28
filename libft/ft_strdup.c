/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:46:39 by hailuo            #+#    #+#             */
/*   Updated: 2024/02/29 13:29:16 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	ret = malloc(sizeof(char) * len);
	if (ret != NULL)
		ft_strlcpy(ret, s, len);
	return (ret);
}
