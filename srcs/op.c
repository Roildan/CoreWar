/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 11:40:03 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 14:17:57 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	print_tab(void)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		ft_printf("%s, %d, [%d, %d, %d], %d, %d, %s, %d, %d\n",
				op_tab[i].name, op_tab[i].nb_param, op_tab[i].type_param[0],
				op_tab[i].type_param[1], op_tab[i].type_param[2],
				op_tab[i].op_code, op_tab[i].nb_cycle, op_tab[i].comment,
				op_tab[i].have_param_byte, op_tab[i].is_int);
		i++;
	}
}

void	get_op_tab(t_op *tab)
{
	int i;

	i = 0;
	while (i < 16)
	{
		tab[i].name = op_tab[i].name;
		tab[i].nb_param = op_tab[i].nb_param;
		tab[i].type_param[0] = op_tab[i].type_param[0];
		tab[i].type_param[1] = op_tab[i].type_param[1];
		tab[i].type_param[2] = op_tab[i].type_param[2];
		tab[i].op_code = op_tab[i].op_code;
		tab[i].nb_cycle = op_tab[i].nb_cycle;
		tab[i].comment = op_tab[i].comment;
		tab[i].have_param_byte = op_tab[i].have_param_byte;
		tab[i].is_int = op_tab[i].is_int;
		i++;
	}
}