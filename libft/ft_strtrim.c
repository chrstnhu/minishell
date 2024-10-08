/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:35:51 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/24 16:02:00 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	if (start >= end)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, start, end - start));
}

/* int	main(void)
{
	const char	*s1 = "cnsbbcanscccan";
	const char	*set = "cans";
	char		*ret;

	ret = ft_strtrim(s1, set);
	printf("Original string: %s\n", s1);
	printf("Trimmed string:  %s\n", ret);
	free(ret);
	return (0);
} */
