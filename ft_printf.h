/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 08:48:30 by rishimot          #+#    #+#             */
/*   Updated: 2020/08/25 23:34:58 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"

# define INIT_FIELD 0
# define INIT_PRECISE -1
# define SUCESS 1
# define FAIL -1
# define ERROR -1
# define LEFT 0
# define NON 1
# define ZERO 2

typedef	struct	s_fomat_information
{
	int			width;
	int			len;
	int			flag;
	int			result;
}				t_flags;

typedef	struct	s_count
{
	int			blank;
	int			minus;
	int			zero;
}				t_cnts;

int				ft_printf(const char *format, ...);
void			process_c(t_flags *fmt_info, va_list *ap);
void			process_s(t_flags *fmt_info, va_list *ap);
void			process_p(t_flags *fmt_info, va_list *ap);
void			process_di(t_flags *fmt_info, va_list *ap);
void			process_u(t_flags *fmt_info, va_list *ap);
void			process_x(t_flags *fmt_info, va_list *ap);
void			process_large_x(t_flags *fmt_info, va_list *ap);
void			process_per(t_flags *fmt_info);
void			ft_putnum(t_flags *fmt_info, long long num, char *base);
void			ft_putstr(t_flags *fmt_info, char *str, int len);
void			fmt_init(t_flags *fmt_info, int len);
void			ft_putchar_n(char c, t_flags *fmt_info);
void			output(char c, int len, t_flags *fmt_info);
int				keta_to_xx(long long ui, int xx);
void		dic_to_xx(long long ui, char *base, int xx, t_flags *fmt_info);
int				max(int a, int b);
int				min(int a, int b);

#endif
