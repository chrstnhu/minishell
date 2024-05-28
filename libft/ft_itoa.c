/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:17:19 by hailuo            #+#    #+#             */
/*   Updated: 2023/12/05 12:40:49 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	len = ft_nbrlen(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	while (n != 0)
	{
		if (n > 0)
			ret[--len] = '0' + (n % 10);
		else
		{
			ret[0] = '-';
			ret[--len] = '0' - (n % 10);
		}
		n /= 10;
	}
	return (ret);
}

/* int	main(void)
{
	int		n1 = 123;
	int		n2 = -456;
	int		n3 = 0;
	char	*s1 = ft_itoa(n1);
	char	*s2 = ft_itoa(n2);
	char	*s3 = ft_itoa(n3);

	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("%s\n", s3);
	free(s1);
	free(s2);
	free(s3);
	return (0);
} */
