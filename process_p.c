/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:04:20 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/24 21:52:20 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	keta_to_hex(long long ui)
{
	int	cnt;

	cnt = 1;
	while (ui / 16 != 0)
	{
		ui /= 16;
		cnt++;
	}
	return (cnt);
}

static void	dic_to_hex(long long ui, char *base)
{
	if (ui < 16)
	{
		ft_putchar_fd(base[ui], 1);
		return ;
	}
	dic_to_hex(ui / 16, base);
	dic_to_hex(ui % 16, base);
}

static void	ft_putnum_out(t_flags *fmt_info, long long num, t_cnts cnt)
{
	if ((*fmt_info).flag == ZERO)
	{
		cnt.zero += cnt.blank;
		cnt.blank = 0;
	}
	if ((*fmt_info).flag != LEFT)
		output(' ', cnt.blank);
	ft_putstr_fd("0x", 1);
	output('0', cnt.zero);
	if (!(num == 0 && (*fmt_info).len == 0))
		dic_to_hex(num, "0123456789abcdef");
	if ((*fmt_info).flag == LEFT)
		output(' ', cnt.blank);
}

static void	ft_putnum_p(t_flags *fmt_info, unsigned long num, int *result)
{
	t_cnts	cnt;
	int		num_len;
	int		len;

	num_len = keta_to_hex(num);
	if (num == 0 && (*fmt_info).len == 0)
		num_len = 0;
	fmt_init(fmt_info, num_len);
	len = max(num_len, (*fmt_info).len);
	cnt.zero = len - num_len;
	len += 2;
	cnt.blank = max(0, (*fmt_info).width - len);
	ft_putnum_out(fmt_info, num, cnt);
	*result += cnt.blank + cnt.zero + num_len + 2;
}

void		process_p(t_flags *fmt_info, va_list *ap, int *result)
{
	unsigned long	num;
	void			*str;

	str = va_arg(*ap, void*);
	num = (unsigned long)str;
	if (num == 0 && (*fmt_info).len == INIT_PRECISE)
	{
		fmt_init(fmt_info, 3);
		ft_putstr(fmt_info, "0x0", 3, result);
	}
	else
		ft_putnum_p(fmt_info, num, result);
}
