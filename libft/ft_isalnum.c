/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:29 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/07 12:18:44 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/* int	main(void)
{
	int	c;

	c = 'A';
	printf("isalnum result: %d\n", isalnum(c));
	printf("ft_isalnum result: %d\n", ft_isalnum(c));
	return (0);
} */
