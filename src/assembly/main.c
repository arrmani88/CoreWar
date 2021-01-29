/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 16:51:36 by anel-bou         ###   ########.fr       */
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

void	initialize_variables(t_env **env)
{
	(*env) = (t_env *)ft_memalloc(sizeof(t_env));
	(*env)->data = (t_data *)ft_memalloc(sizeof(t_data));
}

int     main(int ac, char **av)
{
	t_env *env;

	if (ac > 1 || 1)
	{
		initialize_variables(&env);
		if (!open_file("qwer.s", env))
			return (-1);
		set_initial_data(env);
		tokenize_data(env);
		/* is_input_correct() */
		set_data_in_nodes(env);
	}
	return (0);
}




















/************************************/
	
int     getLastDotIndex(char *s)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == '.')
			j = i;
		i++;
	}
	return (j);
}

char *getFileName(char *s)
{
	int lastDot;
	char *fileName;

	fileName = NULL;
	lastDot = getLastDotIndex(s);
	fileName = ft_strjoin(ft_strsub(s, 0, getLastDotIndex(s)), ".cor");
	return (fileName);
}

int	create_file(char *s, t_env *env)
{
	char *exec_name;

	exec_name = getFileName(s);
	ft_putstr("Writing output program to ");
	ft_putstr(exec_name);
	ft_putendl(" ...");
	env->dst_file = open(exec_name, O_WRONLY | O_CREAT | O_TRUNC , 0644);
	return (0);
}
