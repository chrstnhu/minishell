/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:02:42 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/24 14:54:28 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst && dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if ((i + j) < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/* int	main(void)
{
	char	src[] = "World";
	char	dst[30] = "Hello";
	size_t	len;

	len = ft_strlcat(dst, src, 3);
	printf("text of dst: %s\n", dst);
	printf("length of dst: %zu\n", len);
	return (0);
} */
