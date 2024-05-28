/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:33:01 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/10 10:57:59 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <ctype.h> */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/* int	main(void)
{
	int	c;

	c = 'd';
	printf("original text: %c\n", c);
	printf("toupper text: %c\n", toupper(c));
	printf("ft_toupper text: %c\n", ft_toupper(c));
	return (0);
}
 */