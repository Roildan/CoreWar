/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:59:14 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 15:22:37 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print_zero(t_flags *flags, size_t *count)
{
	int		i;
	char	space;

	i = flags->width <= 0 ? 0 : flags->width - 1;
	space = flags->zero && !flags->left ? '0' : ' ';
	(*count)++;
	if (flags->left)
		ft_putchar('\0');
	*count += i;
	while (i--)
		ft_putchar(space);
	if (!flags->left)
		ft_putchar('\0');
}

void		ft_print_char(unsigned char c, t_flags *flags, size_t *count)
{
	char	space;
	char	*str;
	int		i;

	if (c == '\0')
		return (ft_print_zero(flags, count));
	str = ft_strnew(1);
	str[0] = c;
	space = ' ';
	if (flags->zero && !flags->left)
		space = '0';
	i = flags->width - (int)ft_strlen(str);
	if (i > 0)
		while (i--)
			str = flags->left ?
				ft_str_addi_back(space, str, 1) :
				ft_str_addi_front(space, str, 1);
	ft_print(str, count);
}

void		ft_print_str(char *str, t_flags *flags, size_t *count)
{
	char	space;
	char	*res;
	int		i;

	if (!str)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(str);
	space = ' ';
	if (flags->zero && !flags->left)
		space = '0';
	if (flags->preci != -1 && flags->preci < (int)ft_strlen(res))
		res = ft_strsub(res, 0, (size_t)flags->preci);
	i = flags->width - (int)ft_strlen(res);
	if (i > 0)
		while (i--)
			res = flags->left ?
				ft_str_addi_back(space, res, 1) :
				ft_str_addi_front(space, res, 1);
	ft_print(res, count);
}
