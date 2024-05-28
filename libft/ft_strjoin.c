/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:50:40 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/24 14:02:56 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(sizeof(char) * len);
	if (ret != NULL)
	{
		if (s1)
			ft_strlcpy(ret, s1, len);
		else
			*ret = '\0';
		if (s2)
			ft_strlcat(ret, s2, len);
	}
	return (ret);
}

/* int	main(void)
{
	printf("%s\n", ft_strjoin("trouille", "42"));
	return (0);
}
 */
