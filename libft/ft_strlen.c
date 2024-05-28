/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:40:15 by hailuo            #+#    #+#             */
/*   Updated: 2023/12/14 14:52:24 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* int	main(void)
{
	const char	*c;

	c = "Hello";
	printf("strlen result: %lu\n", strlen(c));
	printf("ft_strlen result: %lu\n", ft_strlen(c));
	return (0);
} */
