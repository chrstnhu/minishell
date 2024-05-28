/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:08:22 by hbaddrul          #+#    #+#             */
/*   Updated: 2024/05/23 12:53:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_reset(t_fmt *fmt)
{
	fmt->minus = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->hashtag = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
	fmt->upper = 0;
	fmt->pad = 0;
	fmt->offset = 0;
}

static void	pf_subprocess(t_fmt *fmt, char *str)
{
	if (*str == '#')
		fmt->hashtag = 1;
	else if (*str == '-')
		fmt->minus = 1;
	else if (*str == ' ')
		fmt->space = 1;
	else if (*str == '+')
		fmt->plus = 1;
	else if (*str == '0' && !ft_isdigit(*(str - 1)))
		fmt->zero = 1;
	else if (ft_isdigit(*str) && (!fmt->dot))
		fmt->width = fmt->width * 10 + *str - '0';
	else if (*str == '.')
		fmt->dot = 1;
	else if (ft_isdigit(*str) && (fmt->dot || fmt->zero))
		fmt->precision = fmt->precision * 10 + *str - '0';
}

static char	*pf_process(t_fmt *fmt, char *str)
{
	int	len;

	len = 0;
	while (*str && !ft_strchr("cspdiuxX%", *str))
		pf_subprocess(fmt, str++);
	if (fmt->minus == 1 || fmt->dot == 1)
		fmt->zero = 0;
	if (fmt->plus == 1)
		fmt->space = 0;
	if (*str == 'c')
		print_c(fmt);
	else if (*str == 's')
		print_s(fmt);
	else if (*str == 'p')
		print_p(fmt, len);
	else if (*str == 'd' || *str == 'i')
		print_i(fmt);
	else if (*str == 'u')
		print_u(*str, 10, fmt);
	else if (*str == 'x' || *str == 'X')
		print_u(*str, 16, fmt);
	else if (*str == '%' && ++fmt->len)
		ft_putchar_fd(*str, 1);
	return (++str);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	t_fmt	fmt;

	ret = 0;
	fmt.len = 0;
	init_reset(&fmt);
	va_start(fmt.args, str);
	while (*str)
	{
		if (*str == '%' && *str++)
		{
			str = pf_process(&fmt, (char *)str);
			init_reset(&fmt);
		}
		else if (++ret)
			ft_putchar_fd(*str++, 1);
	}
	va_end(fmt.args);
	ret += fmt.len;
	return (ret);
}
