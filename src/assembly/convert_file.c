/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:27:56 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/28 19:29:02 by anel-bou         ###   ########.fr       */
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
	while (line[i] && line[i] != ' ')
		if (!(is_char_in_str(line[i++], LABEL_CHARS)))
			return (0);
	if (line[i] != ' ')
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
	return (1);
}

void	tokenize_data(t_env *env)
{
	t_data *data;
	char *line;

	get_next_line(env->src_file, &line);
	env->data->line = line;
	data = env->data;
	while (get_next_line(env->src_file, &line))
	{
		data->next = (t_data *)ft_memalloc(sizeof(t_data));
		data = data->next;
		data->line = line;
	}
}

void	set_pattern_in_nodes(t_opr *opr, char *line)
{
	int i;

	opr->enc_octet = 0;
	i = get_first_char_index(line);
	opr->opr_code = get_operation_code(&line[i]);
	if (is_args_octet_present(opr->opr_code))
		opr->enc_octet = set_args_octet(&line[i]);




}

t_opr	*get_current_opr_code(t_env *env, t_opr *opr)
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

void	convert_file(t_env *env)
{
	set_initial_data(env);
	// write_initial_data(env);
	tokenize_data(env);
	/** check if input correct  **/
	set_data_in_nodes(env);
	
}
