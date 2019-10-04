/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:07:34 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/03/28 16:48:58 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print(char *str, size_t *count)
{
	*count += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	buff[BUFF_SIZE];
	size_t	i;
	size_t	count;

	va_start(ap, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		i = 0;
		while (*format && i < (BUFF_SIZE - 1) && *format != '%')
		{
			count++;
			buff[i++] = *format++;
		}
		buff[i] = '\0';
		ft_putstr(buff);
		if (*format == '%')
			format = ft_parse(format + 1, &count, ap);
	}
	va_end(ap);
	return ((int)count);
}
