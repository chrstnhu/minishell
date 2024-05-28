/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:29 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/07 12:27:47 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}

/* int	main(void)
{
	int	c;

	c = '	';
	printf("isprint result: %d\n", isprint(c));
	printf("ft_isprint result: %d\n", ft_isprint(c));
	return (0);
} */
