/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:30:47 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/28 10:46:29 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}

// solution 2
/* char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
} */

// solution 3
/* char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NUll);
} */

/* int	main(void)
{
	const char	*s;
	int			c;
	char		*result;

	s = "Salut";
	c = 't';
	result = ft_strchr(s, c);
	if (result != NULL)
		printf("Character '%c' found at position: %ld\n", c, result - s);
	return (0);
} */
