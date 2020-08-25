/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 00:42:42 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 22:48:27 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		keta_to_xx(long long ui, int xx)
{
	int	cnt;

	cnt = 1;
	while (ui / xx != 0)
	{
		ui /= xx;
		cnt++;
	}
	return (cnt);
}

static void		dic_to_xx(long long ui, char *base, int xx)
{
	if (ui < xx)
	{
		ft_putchar_fd(base[ui], 1);
		return ;
	}
	dic_to_xx(ui / xx, base, xx);
	dic_to_xx(ui % xx, base, xx);
}

static void		ft_putnum_out(t_flags *fmt_info, t_cnts cnt,\
											long long num, char *base)
{
	if ((*fmt_info).flag == ZERO)
	{
		cnt.zero += cnt.blank;
		cnt.blank = 0;
	}
	if ((*fmt_info).flag != LEFT)
		output(' ', cnt.blank);
	if (cnt.minus == -1)
		ft_putstr_fd("-", 1);
	output('0', cnt.zero);
	if (!(num == 0 && (*fmt_info).len == 0))
		dic_to_xx(num, base, ft_strlen(base));
	if ((*fmt_info).flag == LEFT)
		output(' ', cnt.blank);
}

void			ft_putnum(t_flags *fmt_info, long long num,\
												char *base, int *result)
{
	t_cnts	cnt;
	int		num_len;
	int		len;

	cnt.minus = 1;
	if (num < 0)
		cnt.minus = -1;
	num *= cnt.minus;
	num_len = keta_to_xx(num, ft_strlen(base));
	if (num == 0 && (*fmt_info).len == 0)
		num_len = 0;
	fmt_init(fmt_info, num_len);
	len = max(num_len, (*fmt_info).len);
	cnt.zero = len - num_len;
	if (cnt.minus == -1)
		len++;
	cnt.blank = max(0, (*fmt_info).width - len);
	ft_putnum_out(fmt_info, cnt, num, base);
	*result += cnt.blank + cnt.zero + num_len;
	if (cnt.minus == -1)
		(*result)++;
}
