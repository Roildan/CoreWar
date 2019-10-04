/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:39:49 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 16:38:00 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_round(char *str, size_t i)
{
	while (i && (str[i] == '9' || str[i] == '.'))
	{
		if (str[i] != '.')
			str[i] = '0';
		i--;
	}
	if (i == 0 && str[i] == '9')
	{
		str[i] = '0';
		str = ft_str_addi_front('1', str, 1);
	}
	else
		str[i]++;
	return (str);
}

static char		*ft_prec(char *str, t_flags *flags, long long int_nb,
		long double *dec_nb)
{
	int i;

	i = flags->preci;
	while (i--)
	{
		*dec_nb *= 10;
		int_nb = (long long)*dec_nb;
		*dec_nb -= int_nb;
		str = ft_str_addi_back('0' + int_nb, str, 1);
	}
	return (str);
}

static char		*ft_width(t_bool neg, t_flags *flags, char *str)
{
	char space;

	space = flags->zero && !flags->left ? '0' : ' ';
	if (flags->left)
	{
		if (neg || flags->sign || flags->space)
			str = ft_str_addi_back(space, str, flags->width
					- (int)ft_strlen(str) - 1);
		else
			str = ft_str_addi_back(space, str, flags->width
					- (int)ft_strlen(str));
	}
	else
	{
		if (neg || flags->sign || flags->space)
			str = ft_str_addi_front(space, str, flags->width
					- (int)ft_strlen(str) - 1);
		else
			str = ft_str_addi_front(space, str, flags->width
					- (int)ft_strlen(str));
	}
	return (str);
}

static t_bool	ft_is_special(long double nb, t_flags *flags, size_t *count)
{
	t_bool is_spe;

	is_spe = FALSE;
	if (nb == (long double)(float)1954e100)
	{
		is_spe = TRUE;
		ft_print_str(ft_strdup("inf"), flags, count);
	}
	else if (nb == (long double)(float)-1954e100)
	{
		is_spe = TRUE;
		ft_print_str(ft_strdup("-inf"), flags, count);
	}
	else if (nb != nb)
	{
		is_spe = TRUE;
		ft_print_str(ft_strdup("nan"), flags, count);
	}
	return (is_spe);
}

void			ft_print_float(long double nb, t_flags *flags,
		size_t *count, t_bool neg)
{
	char		*str;
	long long	int_nb;
	long double	dec_nb;
	size_t		i;

	if (ft_is_special(nb, flags, count))
		return ;
	nb = neg ? -nb : nb;
	int_nb = (long long)nb;
	dec_nb = nb - (long double)int_nb;
	str = ft_ntoa_base(int_nb, 0);
	flags->preci = flags->preci == -1 ? 6 : flags->preci;
	if (flags->preci || flags->alt)
		str = ft_str_addi_back('.', str, 1);
	str = ft_prec(str, flags, int_nb, &dec_nb);
	i = ft_strlen(str) - 1;
	if ((dec_nb * 10) == 5.0 && int_nb % 2 == 1 && !flags->preci)
		str = ft_round(str, i);
	else if ((dec_nb * 10) > 5.0)
		str = ft_round(str, i);
	if (flags->width > (int)ft_strlen(str))
		str = ft_width(neg, flags, str);
	str = ft_add_sign(str, flags, neg);
	ft_print(str, count);
}
