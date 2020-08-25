/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:08:05 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 23:28:36 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_flag(char **format)
{
	bool zero;
	bool hypen;

	zero = false;
	hypen = false;
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			zero = true;
		if (**format == '-')
			hypen = true;
		(*format)++;
	}
	if (hypen)
		return (LEFT);
	if (zero)
		return (ZERO);
	return (RIGHT);
}

static int	field_precise(char **format, va_list *ap, int init)
{
	int		result;

	result = init;
	if (**format == '*')
	{
		result = va_arg(*ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		result = 0;
		while (ft_isdigit(**format))
		{
			result = result * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (result);
}

static void	is_type(char **format, va_list *ap, t_flags *fmt_info)
{
	if (**format == 'c')
		process_c(fmt_info, ap);
	else if (**format == 's')
		process_s(fmt_info, ap);
	else if (**format == 'p')
		process_p(fmt_info, ap);
	else if (**format == 'd' || **format == 'i')
		process_di(fmt_info, ap);
	else if (**format == 'u')
		process_u(fmt_info, ap);
	else if (**format == 'x')
		process_x(fmt_info, ap);
	else if (**format == 'X')
		process_large_x(fmt_info, ap);
	else if (**format == '%')
		process_per(fmt_info);
}

static int	spec(char **format, t_flags *fmt_info, va_list *ap)
{
	(*fmt_info).flag = get_flag(format);
	if (**format == '\0')
		return (ERROR);
	(*fmt_info).width = field_precise(format, ap, INIT_FIELD);
	if ((*fmt_info).width < 0)
	{
		(*fmt_info).width *= -1;
		(*fmt_info).flag = LEFT;
	}
	if (**format == '\0')
		return (ERROR);
	(*fmt_info).len = INIT_PRECISE;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '\0')
			return (ERROR);
		(*fmt_info).len = field_precise(format, ap, 0);
		if ((*fmt_info).len < 0)
			(*fmt_info).len = INIT_PRECISE;
		//else if ((*fmt_info).flag == ZERO)
		//	(*fmt_info).flag = RIGHT;
	}
	if (**format == '\0')
		return (ERROR);
	is_type(format, ap, fmt_info);
	return (SUCESS);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	fmt_info;
	char	*fmt;

	va_start(ap, format);
	fmt = (char *)format;
	fmt_info.result = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '\0' || spec(&fmt, &fmt_info, &ap) == ERROR)
			{
				fmt_info.result = -1;
				break;
			}
		}
		else
			ft_putchar_n(*fmt, &fmt_info);
		fmt++;
	}
	va_end(ap);
	return (fmt_info.result);
}
