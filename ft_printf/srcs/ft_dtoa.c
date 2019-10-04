/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:13:42 by armoulin          #+#    #+#             */
/*   Updated: 2019/04/08 14:24:14 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_round(char *str)
{
	size_t i;

	i = ft_strlen(str) - 1;
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

char		*ft_dtoa(double nb, size_t preci)
{
	char		*res;
	double		dec_nb;
	long long	int_nb;

	int_nb = (long long)nb;
	dec_nb = nb - (double)int_nb;
	res = ft_str_addi_back('.', ft_ntoa_base(int_nb, 0), 1);
	while (preci--)
	{
		dec_nb *= 10;
		int_nb = (long long)dec_nb;
		dec_nb -= int_nb;
		res = ft_str_addi_back('0' + int_nb, res, 1);
	}
	if ((dec_nb * 10) > 5.0)
		res = ft_round(res);
	return (res);
}
