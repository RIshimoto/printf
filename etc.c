/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:16:13 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 23:02:27 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_putchar_n(char c, t_flags *fmt_info)
{
	ft_putchar_fd(c, 1);
	fmt_info->result++;
}

void	output(char c, int len, t_flags *fmt_info)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_n(c, fmt_info);
		i++;
	}
}

void	fmt_init(t_flags *fmt_info, int len)
{
	if ((*fmt_info).len == INIT_PRECISE)
		(*fmt_info).len = len;
}
