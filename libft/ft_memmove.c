/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:56:11 by hailuo            #+#    #+#             */
/*   Updated: 2024/05/16 20:23:06 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* #include <string.h>
#include <stdio.h> */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*ret;

	if (!dest && !src)
		return (NULL);
	ret = dest;
	if (dest > src)
	{
		src += n;
		dest += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}	
	else
		while (n--)
			*(char *)dest++ = *(char *)src++;
	return (ret);
}

/* int	main(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};


	char *dest = ft_memmove(s0, s, 7);
	// char *dest = ft_memmove(s, s + 2, 0);
	// char *dest = ft_memmove(s, s + 2, 2);
	// char *dest = ft_memmove(sResult + 1, sResult, 2);
	printf("ft_memmove result: %s\n", dest);
	return (0);
} */
