/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:23:49 by hailuo            #+#    #+#             */
/*   Updated: 2023/11/29 18:02:34 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>

void	test(unsigned int i, char *c)
{
	i = 0;
	if (c[i] >= 'a' && c[i] <= 'z')
		c[i] = c[i] - 32;
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* int	main(void)
{
	char	str[] = "hello";

	ft_striteri(str, test);
	printf("%s\n", str);
	return (0);
}
 */