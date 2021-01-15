/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:27:56 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/15 11:30:30 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		is_label(char *str)
{
	if (str_composed_of)
}

void	translate_code(t_env *env)
{
	char *line;
	
	while (get_next_line(env->src_file, &line))
	{
		if (is_label(line))	
			;
	}
}

void	convert_file(t_env *env)
{
	set_initial_data(env);
	write_initial_data(env);
	translate_code(env);
}