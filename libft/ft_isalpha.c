/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:29 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/17 15:49:22 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/* int	main(void)
{
	int	c;

	c = 'x';
	printf("isalpha result: %d\n", isalpha(c));
	printf("ft_isalpha result: %d\n", ft_isalpha(c));
	return (0);
} */
