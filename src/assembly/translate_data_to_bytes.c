/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_data_to_bytes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:20:59 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/30 12:03:06 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

unsigned char	set_args_octet(char *line)
{
	unsigned char	oct;
	int				i;
	int				shf;

	oct = 0;
	i = -1;
	shf = 6;
	while (line[++i] && shf)
	{
		if (is_arg_first_char(line, i))
		{
			oct = oct | (get_current_argument_code(&line[i]) << shf);
			shf -= 2;
		}
	}
	return (oct);
}

void	fill_node_by_operation(t_opr *opr, char *line)
{
	int i;

	opr->enc_octet = 0;
	i = get_first_char_index(line);
	opr->opr_code = get_operation_code(&line[i]);
	if (is_args_octet_present(opr->opr_code))
		opr->enc_octet = set_args_octet(&line[i]);
	while (line[++i] && !IS_SPACE(line[i]))
		;
	++i;

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

void	translate_data_to_bytes(t_env *env)
{
	t_data			*data;
	t_opr			*opr;
	int i;

	data = env->data;
	while (data)
	{
		i = 0;
		if (is_operation(data->line) || (i = is_label_operation_in_same_line(data->line)))
		{
			opr = get_current_opr_node(env, opr);
			fill_node_by_operation(opr, &(data->line)[i]);
		}
		data = data->next;
	}




}