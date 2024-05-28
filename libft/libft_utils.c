/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:45:27 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/02/27 12:43:23 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(t_fmt *fmt)
{
	fmt->hashtag = 0;
	fmt->space = 0;
	fmt->plus = 0;
}

void	ft_putunbr_base_fd(unsigned long long n, int base, int fd)
{
	const char	*digits = "0123456789abcdef";

	if (n / base)
		ft_putunbr_base_fd(n / base, base, fd);
	ft_putchar_fd(digits[n % base], fd);
}

void	ft_putfnbr_base_fd(long long n, int base, t_fmt *fmt, int fd)
{
	int			sign;
	const char	*digits = "0123456789abcdef";

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	else if (n > 0 && fmt->hashtag && fmt->upper)
		ft_putstr_fd("0X", 1);
	else if (n > 0 && fmt->hashtag && !fmt->upper)
		ft_putstr_fd("0x", 1);
	else if (fmt->space)
		ft_putchar_fd(' ', fd);
	else if (fmt->plus)
		ft_putchar_fd('+', fd);
	if (fmt->upper)
		digits = "0123456789ABCDEF";
	while (fmt->pad-- > 0)
		ft_putchar_fd('0', fd);
	reset(fmt);
	if (n / base)
		ft_putfnbr_base_fd(n / base * sign, base, fmt, fd);
	ft_putchar_fd(digits[n % base * sign], fd);
}

void	pad_set_i(int base, t_fmt *fmt, int n)
{
	if (fmt->minus)
	{
		if (!(fmt->dot && fmt->precision == 0 && n == 0))
			ft_putfnbr_base_fd(n, base, fmt, 1);
	}
	while (fmt->offset--)
		ft_putchar_fd(' ', 1);
	if (!fmt->minus)
	{
		if (!(fmt->dot && fmt->precision == 0 && n == 0))
			ft_putfnbr_base_fd(n, base, fmt, 1);
	}
}

void	pad_set_u(int base, t_fmt *fmt, unsigned int n)
{
	if (fmt->minus)
	{
		if (!(fmt->dot && fmt->precision == 0 && n == 0))
			ft_putfnbr_base_fd(n, base, fmt, 1);
	}
	while (fmt->offset--)
		ft_putchar_fd(' ', 1);
	if (!fmt->minus)
	{
		if (!(fmt->dot && fmt->precision == 0 && n == 0))
			ft_putfnbr_base_fd(n, base, fmt, 1);
	}
}
