/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_diux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 00:47:02 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/24 19:47:27 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_di(t_flags *fmt_info, va_list *ap, int *result)
{
	int		num;

	num = va_arg(*ap, int);
	ft_putnum(fmt_info, num, "0123456789", result);
}

void	process_u(t_flags *fmt_info, va_list *ap, int *result)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	ft_putnum(fmt_info, num, "0123456789", result);
}

void	process_x(t_flags *fmt_info, va_list *ap, int *result)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	ft_putnum(fmt_info, num, "0123456789abcdef", result);
}

void	process_large_x(t_flags *fmt_info, va_list *ap, int *result)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	ft_putnum(fmt_info, num, "0123456789ABCDEF", result);
}
