/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:16:13 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/24 20:08:36 by rishimot         ###   ########.fr       */
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

void	output(char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
}
