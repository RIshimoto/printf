/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:04:20 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 23:21:00 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum_out(t_flags *fmt_info, long long num, t_cnts cnt)
{
	if ((*fmt_info).flag == ZERO)
	{
		cnt.zero += cnt.blank;
		cnt.blank = 0;
	}
	if ((*fmt_info).flag != LEFT)
		output(' ', cnt.blank, fmt_info);
	ft_putchar_n('0', fmt_info);
	ft_putchar_n('x', fmt_info);
	output('0', cnt.zero, fmt_info);
	if (!(num == 0 && (*fmt_info).len == 0))
		dic_to_xx(num, "0123456789abcdef", 16, fmt_info);
	if ((*fmt_info).flag == LEFT)
		output(' ', cnt.blank, fmt_info);
}

static void	ft_putnum_p(t_flags *fmt_info, unsigned long num)
{
	t_cnts	cnt;
	int		num_len;
	int		len;

	num_len = keta_to_xx(num, 16);
	if (num == 0 && (*fmt_info).len == 0)
		num_len = 0;
	fmt_init(fmt_info, num_len);
	len = max(num_len, (*fmt_info).len);
	cnt.zero = len - num_len;
	len += 2;
	cnt.blank = max(0, (*fmt_info).width - len);
	ft_putnum_out(fmt_info, num, cnt);
}

void		process_p(t_flags *fmt_info, va_list *ap)
{
	unsigned long	num;
	void			*str;

	str = va_arg(*ap, void*);
	num = (unsigned long)str;
	if (num == 0 && (*fmt_info).len == INIT_PRECISE)
	{
		fmt_init(fmt_info, 3);
		ft_putstr(fmt_info, "0x0", 3);
	}
	else
		ft_putnum_p(fmt_info, num);
}
