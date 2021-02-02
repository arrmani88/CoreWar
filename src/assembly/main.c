/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/02/02 19:30:21 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int	open_file(char *s, t_env *env)
{
	if ((env->src_file = open(s, O_RDONLY)) == -1)
	{
		ft_putendl_fd("unable to open this file", 2);
		return (0);
	}
	return (1);
}

void	allocate_variables(t_env **env)
{
	(*env) = (t_env *)ft_memalloc(sizeof(t_env));
	(*env)->data = (t_data *)ft_memalloc(sizeof(t_data));
	(*env)->bgn_data = (char *)ft_memalloc(sizeof(char) * BGN_DATA);
	(*env)->champion = (char *)ft_memalloc(sizeof(char) * CHAMP_MAX_SIZE);
}

void	print_labels(t_env *env)
{
	t_label *l = env->label;
	printf("\n");
	while (l)
	{
		printf("lblname=[%s]\tpos=[%d]\n", l->label_name, l->label_position);
		l = l->next;
	}
}

void	print_data(t_env *env)
{
	t_data *d = env->data;
	printf("\n");
	while (d)
	{
		printf("curr=[%d]\tline=[%s]\n", d->current_octets, d->line);
		d = d->next;
	}
	
}

int     main(int ac, char **av)
{
	t_env *env;

	char *p = "vm_champs/champs/jumper.s";
	if (ac > 1 || 1)
	{
		
		allocate_variables(&env);
		if (!open_file(av[ac - 1], env))
			return (-1);
		organize_beginning_data(env);
		tokenize_data(env);
		/* is_input_correct() */
		translate_data_to_code(env);
		create_file(av[ac - 1], env);
		env->sup = 0;
		write_bytecode_in_file(env);
	
	
	// print_labels(env);
	// print_data(env);
	}
	return (0);
}

// f='vm_champs/champs/42' && ./asm $f.s && printf "\33c" &&  xxd $f.cor |pbcopy
// ***********
// printf "\33c" && f='vm_champs/champs/barriere' && ./vm_champs/asm $f.s &&  xxd $f.cor |pbcopy


/*

gobepc:	st r1,:buff
	st r6,-4
	ld :buff,r1
debut:	ld %0,r7
	zjmp %:suite

goboucle0:	live %66
		ldi %-5,r3,r1
		sti r1,%-173,r3
		add r3,r4,r3
		xor r5,r3,r6
		zjmp %:finboucle0
		ld %0,r7
		zjmp %:goboucle0
finboucle0:	xor r3,r3,r3
		zjmp %-207

buff:	st r1,r1	

*/