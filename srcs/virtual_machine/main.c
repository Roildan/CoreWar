/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoinsot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:41:48 by lpoinsot          #+#    #+#             */
/*   Updated: 2019/10/11 15:20:15 by lpoinsot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/virtual_machine/corewar.h"

void		create_champ(char *name, int champ_nb, t_vm *vm)
{
	char	*champ_name;
	int		i;

	i = 0;
	if (!(ft_strstr(name, ".cor\0")))
		exit_msg("invalid champ name");
	champ_name = ft_strsub(name, 0, (size_t)(ft_strlen(name) - 4));
	if (ft_strlen(name) > PROG_NAME_LENGTH)
		exit_msg("champ name too long");
	if (vm->nb_champs == 4)
		exit_msg("too many champions");
	while (i < vm->nb_champs)
	{
		if (!(ft_strcmp(champ_name, vm->champs[i++].name)))
			exit_msg("champ name used twice, please change a name");
	}
	i = 0;
	if (champ_nb)
		while (i < vm->nb_champs)
		{
			if (vm->champs[i].id == champ_nb)
				exit_msg("champ_number already used");
			i++;
		}
	else
	{
		champ_nb = 1;
		while (i < vm->nb_champs)
		{
			if (champ_nb == vm->champs[i].id)
			{
				i = 0;
				champ_nb++;
			}
			else
				i++;
		}
	}
	vm->champs[vm->nb_champs] = *init_champ(champ_name, champ_nb);
	vm->nb_champs++;
	ft_printf("%d\n", vm->nb_champs);
}

void		get_opt_champs(int ac, char **av, t_vm *vm)
{
	//int		i;
	int		champ_nb;
	int		arg_nb;

	//i = 0;
	arg_nb = 1;
	champ_nb = 0;
	while (arg_nb < ac)
	{
		if (ft_strstr(av[arg_nb], "-n"))
		{
			arg_nb++;
			if ((arg_nb >= ac) || ((champ_nb = ft_atoi(av[arg_nb])) > 4)
					|| champ_nb < 1)
				exit_msg("invalid champ number");
			arg_nb++;
			if (arg_nb < ac)
				create_champ(av[arg_nb], champ_nb, vm);
			else
				exit_msg("No champ after -n");
			champ_nb = 0;
		}
		else if (ft_strstr(av[arg_nb], "-dump"))
		{
			arg_nb++;
			if ((arg_nb >= ac) || ((vm->dump = ft_atoi(av[arg_nb])) < 1))
				exit_msg("invalid dump number");
		}
		else
			create_champ(av[arg_nb], champ_nb, vm);
		arg_nb++;
	}
}

static void		print_champs(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < vm->nb_champs)
	{
		ft_printf("champ name: %s , champ id: %d \n", vm->champs[i].name, vm->champs[i].id);
		i++;
	}
		ft_printf("dump = %d\n", vm->dump);
}

int			main(int ac, char **av)
{
	t_vm		*vm;

	if (ac < 3)
		exit_msg("Not enough arguments.");
	vm = init_vm();
	get_opt_champs(ac, av, vm);
	print_champs(vm);
	return (0);
}
