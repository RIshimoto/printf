/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 00:43:49 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/24 19:45:58 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_flags *fmt_info, char *str, int len, int *result)
{
	char	c;
	int		i;
	int		j;
	int		width;
	int		insert_index;

	len = min(len, (*fmt_info).len);
	width = max((*fmt_info).width, len);
	insert_index = max(0, (*fmt_info).width - len);
	c = ' ';
	if ((*fmt_info).flag == LEFT)
		insert_index = 0;
	if ((*fmt_info).flag == ZERO)
		c = '0';
	i = -1;
	j = 0;
	while (++i < width)
	{
		if (insert_index <= i && i < insert_index + len)
			ft_putchar_fd(str[j++], 1);
		else
			ft_putchar_fd(c, 1);
	}
	*result += width;
}

void	fmt_init(t_flags *fmt_info, int len)
{
	if ((*fmt_info).len == INIT_PRECISE)
		(*fmt_info).len = len;
}
