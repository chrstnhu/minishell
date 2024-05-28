/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:27:08 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/28 10:46:17 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <string.h>
#include <stdio.h> */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	*s;
	int			c;
	char		*result;

	s = "Hello World";
	c = '\0';
	result = ft_strrchr(s, c);
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", c, result - s);
	return (0);
} */
