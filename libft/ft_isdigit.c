/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:29 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/17 15:49:34 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

/* int	main(void)
{
	int	c;

	c = 'c';
	printf("isdigit result: %d\n", isdigit(c));
	printf("ft_isdigit result: %d\n", ft_isdigit(c));
	return (0);
} */
