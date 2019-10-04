/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:18:09 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/25 16:42:59 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_flags		ft_init_flags(void)
{
	t_flags flags;

	flags.alt = FALSE;
	flags.zero = FALSE;
	flags.left = FALSE;
	flags.space = FALSE;
	flags.sign = FALSE;
	flags.width = -1;
	flags.preci = -1;
	flags.mod = 0;
	return (flags);
}

static const char	*ft_get_opt(const char *str, t_flags *flags)
{
	while (*str)
	{
		if (*str == '#')
			flags->alt = TRUE;
		else if (*str == '0')
			flags->zero = TRUE;
		else if (*str == '-')
			flags->left = TRUE;
		else if (*str == ' ')
			flags->space = TRUE;
		else if (*str == '+')
			flags->sign = TRUE;
		else
			break ;
		str++;
	}
	if (flags->left)
		flags->zero = FALSE;
	return (str);
}

static const char	*ft_get_width_preci(const char *str, t_flags *flags)
{
	int nb;

	nb = ft_atoi(str);
	if (nb)
		flags->width = nb;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '.')
		return (str);
	str++;
	nb = ft_atoi(str);
	flags->preci = nb;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

static const char	*ft_get_mod(const char *str, t_flags *flags)
{
	if (*str == 'h')
	{
		flags->mod = 2;
		if (*(str + 1) == 'h')
		{
			flags->mod = 1;
			str++;
		}
	}
	else if (*str == 'l')
	{
		flags->mod = 3;
		if (*(str + 1) == 'l')
		{
			flags->mod = 4;
			str++;
		}
	}
	else if (*str == 'L')
		flags->mod = 5;
	else
		return (str);
	return (str + 1);
}

const char			*ft_parse(const char *str, size_t *count, va_list ap)
{
	t_flags flags;

	flags = ft_init_flags();
	str = ft_get_opt(str, &flags);
	str = ft_get_width_preci(str, &flags);
	str = ft_get_mod(str, &flags);
	str = ft_conversion(str, &flags, count, ap);
	return (str);
}
