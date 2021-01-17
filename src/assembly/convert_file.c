/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:27:56 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/15 19:36:51 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		is_empty_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '#')
			return(1);
		else if (line[i] != ' ' && line[i] != '\t')
			return(0);
	}
	return (1);
}

int		is_operation(char *line)
{
	int i;

	i = get_first_char_index(line);
	while (line[i++] && line[i++] != ':')
		if (!(is_char_in_str(line[i], LABEL_CHARS)))
			return (0);
	if (line[i] != ':')
		return (0);
	if (line[++i] == '%' || line[i] == 'r' || (line[i] >= '0' && line[i] <= '9'))
		return (1);
	return(0);
}

int		is_label(t_env *env, char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i] && str[i] != ':')
	{
		j = -1;
		while (LABEL_CHARS[++j] && str[i] != LABEL_CHARS[j])
			;
		if (LABEL_CHARS[j] == 0)
			return(0);
	}
	if (str[i] == 0 || i == 0)
		return (0);
	if (is_operation(&str[++i]))
		write_operation(str);
		// write_operation(env, str);
		
	return (1);
}

void	translate_code(t_env *env)
{
	char *line;
	
	while (get_next_line(env->src_file, &line))
	{
		if (is_label(env, line))
		{
			while (is_empty_line(line))
			{
				ft_memdel((void**)&line);
				get_next_line(env->src_file, &line);
			}
			if (is_operation(line))
				write_operation(line);
				// write_operation(env, line);
		}
		ft_memdel((void**)&line);
	}
}

void	convert_file(t_env *env)
{
	set_initial_data(env);
	write_initial_data(env);
	translate_code(env);
}