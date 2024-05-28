/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:59:16 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/08 12:18:02 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*dest;

	dest = s;
	while (n--)
		*(char *)s++ = (unsigned char)c;
	return (dest);
}

/* int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "Hello";
	int		c;
	size_t	n;

	c = '2';
	n = 3;
	memset(s1, c, n);
	ft_memset(s2, c, n);
	printf("memset result: %s\n", s1);
	printf("ft_memset result: %s\n", s2);
	return (0);
} */
