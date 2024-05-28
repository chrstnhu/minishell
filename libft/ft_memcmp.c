/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:05:28 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/17 12:08:54 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

/* int	main(void)
{
	const void	*s1 = "Hello";
	const void	*s2 = "How";
	size_t		n;

	n = 3;
	printf ("result memcmp: %d\n", memcmp(s1, s2, n));
	printf ("result ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
	return (0);
} */
