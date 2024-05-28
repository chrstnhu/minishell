/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:29:43 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/17 12:23:33 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

/* int	main(void)
{
	const void	*s = "Hello";
	int	c	= 'o';
	size_t	n = 6;
	printf("%p\n", memchr(s, c, n));
	printf("%p\n", ft_memchr(s, c, n));
	return (0);
} */
