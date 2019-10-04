/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:54:24 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/04/10 14:40:56 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_flags
{
	t_bool			alt;
	t_bool			zero;
	t_bool			left;
	t_bool			space;
	t_bool			sign;
	int				width;
	int				preci;
	int				mod;
}					t_flags;

const char			*ft_parse(const char *str, size_t *count, va_list ap);
const char			*ft_conversion(const char *str, t_flags *flags,
		size_t *count, va_list ap);
char				*ft_add_sign(char *str, t_flags *flags, t_bool neg);
void				ft_is_sdeci(t_flags *flags, size_t *count, va_list ap);
void				ft_is_udeci(t_flags *flags, size_t *count, va_list ap);
void				ft_is_oct(t_flags *flags, size_t *count, va_list ap);
void				ft_is_hex(t_flags *flags, size_t *count, va_list ap, int i);
void				ft_is_float(t_flags *flags, size_t *count, va_list ap);
void				ft_print_percent(t_flags *flags, size_t *count);
void				ft_print_char(unsigned char c, t_flags *flags,
		size_t *count);
void				ft_print_str(char *str, t_flags *flags, size_t *count);
void				ft_print_sdeci(long nb, t_flags *flags, size_t *count);
void				ft_print_udeci(unsigned long nb, t_flags *flags,
		size_t *count);
void				ft_print_oct(unsigned long nb, t_flags *flags,
		size_t *count);
void				ft_print_hex(unsigned long nb, t_flags *flags,
		size_t *count, int base);
void				ft_print_pointer(void *p, t_flags *flags, size_t *count);
void				ft_print_float(long double nb, t_flags *flags,
		size_t *count, t_bool neg);
void				ft_print(char *str, size_t *count);
int					ft_printf(const char *format, ...);

#endif
