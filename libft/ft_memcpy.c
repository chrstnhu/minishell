/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:22:15 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/24 12:21:47 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}
/* int	main(void)
{
	char	src[] = "";
	char	dest[100];
	size_t	n;

	n = 0;
	printf("before ft_memcpy: %s\n", src);
	ft_memcpy(dest, src, n);
	printf("ft_memcpy result: %s\n", dest);
	return (0);
} */
