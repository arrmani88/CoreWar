/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_in_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:20:59 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 12:45:22 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	set_pattern_in_nodes(t_opr *opr, char *line)
{
	int i;

	opr->enc_octet = 0;
	i = get_first_char_index(line);
	opr->opr_code = get_operation_code(&line[i]);
	if (is_args_octet_present(opr->opr_code))
		opr->enc_octet = set_args_octet(&line[i]);
	



}

t_opr	*get_current_opr_node(t_env *env, t_opr *opr)
{
	if (!env->opr)
	{
		env->opr = (t_opr *)ft_memalloc(sizeof(t_opr));
		return (env->opr);
	}
	else
	{
		opr->next = (t_opr *)ft_memalloc(sizeof(t_opr));
		return (opr->next);
	}
}

void	set_data_in_nodes(t_env *env)
{
	t_data			*data;
	t_opr			*opr;
	int				i;
	int				op_code;
	unsigned char	args_oct;

	data = env->data;
	while (data)
	{
		if (is_operation(data->line))
			opr = get_current_opr_node(env, opr);
			set_pattern_in_nodes(opr, data->line);
	}




}