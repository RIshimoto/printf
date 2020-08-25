/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:53:23 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/19 08:05:01 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n, size_t len)
{
	char		*p;
	char		*q;
	size_t		i;
	size_t		start;

	if (dest == NULL && src == NULL)
		return (0);
	p = (char *)dest;
	q = (char *)src;
	i = 0;
	start = n;
	while (start < len)
	{
		p[start] = q[i];
		i++;
		start++;
	}
	return (dest);
}
