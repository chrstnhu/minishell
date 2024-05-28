/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:10:18 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/10 11:23:19 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int	main(void)
{
	int	result;

	result = ft_isascii(128);
	if (result)
		printf("is ASCII: %d\n", result);
	else
		printf("is not ASCII: %d\n", result);
	return (0);
} */
