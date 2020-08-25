/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_csper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:58:43 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 23:03:39 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_c(t_flags *fmt_info, va_list *ap)
{
	unsigned int	ui;
	char			c;
	char			str[2];

	ui = va_arg(*ap, unsigned int);
	c = (char)ui;
	str[0] = c;
	str[1] = '\0';
	fmt_init(fmt_info, 1);
	ft_putstr(fmt_info, str, 1);
}

void	process_s(t_flags *fmt_info, va_list *ap)
{
	char	*str;

	if ((str = va_arg(*ap, char*)) == NULL)
		str = "(null)";
	fmt_init(fmt_info, ft_strlen(str));
	ft_putstr(fmt_info, str, ft_strlen(str));
}

void	process_per(t_flags *fmt_info)
{
	char	str[2];

	str[0] = '%';
	str[1] = '\0';
	fmt_init(fmt_info, 1);
	ft_putstr(fmt_info, str, 1);
}
