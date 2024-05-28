/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hailuo <hailuo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 00:50:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/02/27 12:42:52 by hailuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_c(t_fmt *fmt)
{
	const char	c = va_arg(fmt->args, int);

	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - 1;
	fmt->len += fmt->offset + 1;
	if (fmt->minus)
		ft_putchar_fd(c, 1);
	while (fmt->offset--)
		ft_putchar_fd(' ', 1);
	if (!fmt->minus)
		ft_putchar_fd(c, 1);
}

void	print_s(t_fmt *fmt)
{
	int			len;
	const char	*str = va_arg(fmt->args, char *);

	if (!str && (fmt->precision >= 6 || fmt->precision == 0))
		str = "(null)";
	else if (!str)
		str = "";
	len = ft_strlen(str);
	if (!fmt->dot || fmt->precision > len)
		fmt->precision = len;
	if (fmt->width > fmt->precision)
		fmt->offset = fmt->width - fmt->precision;
	fmt->len += fmt->offset + fmt->precision;
	if (fmt->minus)
		ft_putnstr_fd((char *)str, fmt->precision, 1);
	while (fmt->offset--)
		ft_putchar_fd(' ', 1);
	if (!fmt->minus)
		ft_putnstr_fd((char *)str, fmt->precision, 1);
}

void	print_p(t_fmt *fmt, int len)
{
	const void						*ptr = va_arg(fmt->args, void *);
	const unsigned long long		n = (unsigned long long)ptr;

	len = ft_unbrlen(n, 16) + 2;
	if (!ptr)
		len = 5;
	if (fmt->width > len)
		fmt->offset = fmt->width - len;
	fmt->len += fmt->offset + len;
	if (!fmt->minus)
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
	if (!ptr)
		ft_putstr_fd("(nil)", 1);
	if (ptr)
		ft_putstr_fd("0x", 1);
	if (ptr)
		ft_putunbr_base_fd(n, 16, 1);
	if (fmt->minus)
	{
		while (fmt->offset--)
			ft_putchar_fd(' ', 1);
	}
}

void	print_i(t_fmt *fmt)
{
	const int	n = va_arg(fmt->args, int);
	int			len;
	int			alen;

	len = ft_nbrlen(n, 10);
	if (fmt->dot && fmt->precision == 0 && n == 0)
		len = 0;
	alen = len;
	if (n < 0)
		alen = alen - 1;
	if (fmt->width <= len)
		fmt->width = len;
	if (fmt->width > len && fmt->zero)
		fmt->pad = fmt->width - alen;
	if (fmt->dot && fmt->precision > alen)
		fmt->pad = fmt->precision - alen;
	if (fmt->zero && n < 0 && fmt->pad)
		--fmt->pad;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	if ((fmt->space || fmt->plus) && n >= 0 && ++fmt->len && fmt->offset)
		--fmt->offset;
	fmt->len += fmt->offset + fmt->pad + len;
	pad_set_i(10, fmt, n);
}

void	print_u(char c, int base, t_fmt *fmt)
{
	const unsigned int	n = va_arg(fmt->args, unsigned int);
	int					len;

	len = ft_unbrlen(n, base);
	if (fmt->dot && fmt->precision == 0 && n == 0)
		len = 0;
	if (c == 'X')
		fmt->upper = 1;
	if (fmt->hashtag && n > 0)
		fmt->len += 2;
	if (fmt->width <= len)
		fmt->width = len;
	if (fmt->width > len && fmt->zero)
		fmt->pad = fmt->width - len;
	if (fmt->precision > len)
		fmt->pad = fmt->precision - len;
	if (fmt->width > fmt->pad + len)
		fmt->offset = fmt->width - fmt->pad - len;
	fmt->len += fmt->offset + fmt->pad + len;
	pad_set_u(base, fmt, n);
}
