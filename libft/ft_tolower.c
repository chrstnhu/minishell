/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:58:30 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/10 11:04:10 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <ctype.h> */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/* int	main(void)
{
	int	c;

	c = 'D';
	printf("original text: %c\n", c);
	printf("tolower text: %c\n", tolower(c));
	printf("ft_tolower text: %c\n", ft_tolower(c));
	return (0);
} */
