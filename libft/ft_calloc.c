/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:41:38 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/29 17:53:40 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (size && nmemb > (SIZE_MAX / size))
		return (NULL);
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

/* int	main(void)
{
	size_t	nmemb = 7;
	size_t	size = sizeof(int);
	int		*arr = (int *)ft_calloc(nmemb, size);

	for (size_t i = 0; i < nmemb; ++i)
		printf("%d", arr[i]);
	free(arr);
	return (0);
} */
