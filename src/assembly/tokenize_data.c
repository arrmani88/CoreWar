/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:12:14 by anel-bou          #+#    #+#             */
/*   Updated: 2021/02/01 14:43:09 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	save_label_position(char *line, int current_bytes, t_env *env)
{
	int i;
	int j;

	j = -1;
	while (IS_SPACE(line[++j]))
		;
	--j;
	i = j - 1;
	while (line[++i] && line[i] != LABEL_CHAR)
		;
	if (!env->label)
	{
		env->label = (t_label *)ft_memalloc(sizeof(t_label));
		env->lbl = env->label;
	}
	else
	{
		env->lbl->next = (t_label *)ft_memalloc(sizeof(t_label));
		env->lbl = env->lbl->next;
	}
	env->lbl->label_name = ft_strsub(line, j, i);
	env->lbl->label_position = current_bytes;
}

int		is_label_operation_in_same_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		i++;
	while (IS_SPACE(line[++i]))
		;
	if (is_operation(&line[i]))
		return (i);
	return (0);
}

void	save_line(t_env *env, char *line, int *current_bytes)
{
	int i;
	
	env->dt->next = (t_data *)ft_memalloc(sizeof(t_data));
	env->dt = env->dt->next;
	env->dt->line = line;
	
	env->dt->current_octets = *current_bytes;	
	if (is_label(line))
	{
		save_label_position(line, *current_bytes, env);
		if ((i = is_label_operation_in_same_line(line)) > 0)
			*current_bytes += get_operation_size(env, &line[i]);
	}
	else if (is_operation(line))
	{
		*current_bytes += get_operation_size(env, line);
	}
}

void	tokenize_data(t_env *env)
{
	char *line;
	int		current_bytes;
	int i;

	current_bytes = 0;
	get_next_line(env->src_file, &line);
	env->data->line = line;
	env->dt = env->data;
	while (get_next_line(env->src_file, &line))
	{
		save_line(env, line, &current_bytes);
		/***/
	}
	printf("\n");
}
