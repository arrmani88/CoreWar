/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:26:06 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/31 19:33:17 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	write_bytes(int	num, int size)
{
	
}

void	write_operation(t_env *env, t_opr *opr)
{
	write_bytes();
}

void	write_bytecode_in_file(t_env *env)
{
	t_opr *opr;

	write_beginning_data(env);
	opr = env->opr;
	while (opr)
	{
		write_operation(env, opr);
		opr = opr->next;
	}
	
}