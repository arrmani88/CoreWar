/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 10:48:59 by anel-bou          #+#    #+#             */
/*   Updated: 2021/03/06 15:21:40 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	delete_data(t_env *env)
{
	t_data *ptr;
	t_data *nxt;
	
	ptr = env->data;
	while (ptr)
	{
		nxt = ptr->next;
		ft_memdel((void **)&(ptr->line));
		ft_memdel((void **)&ptr);
		ptr = nxt;
	}	
}

void	delete_labels(t_env *env)
{
	t_label *lbl;
	t_label *nxt;

	lbl = env->label;
	while (lbl)
	{
		nxt = lbl->next;
		ft_memdel((void **)&(lbl->label_name));
		ft_memdel((void **)&lbl);
		lbl = nxt;
	}
}

void	delete_opr(t_env *env)
{
	t_opr *opr;
	t_opr *nxt;

	opr = env->opr;
	while (opr)
	{
		nxt = opr->next;
		ft_memdel((void **)&opr);
		opr = nxt;
	}
}

void	liberate_memory(t_env *env)
{
	delete_data(env);
	delete_labels(env);
	delete_opr(env);
	ft_memdel((void **)&(env->bgn_data));
	ft_memdel((void **)&(env->champion));
	ft_memdel((void **)&env);
}
