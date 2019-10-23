/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:59:19 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 15:20:03 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/printf.h"
#include "../includes/error.h"

void			exit_msg(char *error_msg)
{
	ft_putendl(error_msg);
	exit(1);
}
