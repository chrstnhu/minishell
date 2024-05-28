/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:27:00 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/20 12:17:51 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc (sizeof(char) * (len + 1));
	if (ret != NULL)
		ft_strlcpy(ret, s + start, len + 1);
	return (ret);
} */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc (sizeof(char) * (len + 1));
	if (ret != NULL)
		ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

/* int	main(void)
{
	char	*ret;

	ret = ft_substr("Hello World", 5, 4);
	printf("%s\n", ret);
	return (0);
} */
