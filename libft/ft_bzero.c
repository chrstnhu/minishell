/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:49:24 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/08 12:19:14 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "Hello";
	size_t	n;

	n = 3;
	bzero(s1, n);
	ft_bzero(s2, n);
	printf("bezero result: %s\n", s1);
	printf("ft_bzero result: %s\n", s2);
	return (0);
} */
