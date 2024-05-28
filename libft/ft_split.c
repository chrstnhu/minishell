/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:46:18 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/29 11:29:21 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */
#include "libft.h"

static size_t	ft_countword(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

void	ft_free_result(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = ft_calloc((ft_countword(s, c) + 1), sizeof(char *));
	if (!ret)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i] = ft_substr(s - len, 0, len);
			if (!ret[i++])
				return (ft_free_result(ret), NULL);
		}
		else
			++s;
	}
	return (ret);
}

/* static int	ft_countword(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[n] = '\0';
	return (result);
	free (result);
}

void	ft_free_result(char **result)
{
	int i;
	
	i = 0;
	while (result[i])
		free (result[i++]);
	free (result);		
}

char	**ft_split(const char *s, char c)
{
	int			i;
	char		**result;
	const char	*start;

	if (!s)
		return (NULL);
	result = ft_calloc((ft_countword(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i] = strndup(start, s - start);
			if (!result[i++])
				return (ft_free_result(result), NULL);
		}
		else
			s++;
	}
	return (result);
}

int	main(void)
{
	const char	*s = "This is a test sing";
	char		**result = ft_split(s, ' ');
	size_t		i = 0;

	if (!result)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	while (result[i])
	{
		printf("%s\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}  */