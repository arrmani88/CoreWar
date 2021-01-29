/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:12:14 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 19:25:26 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		get_t_dir_size(int op)
{
	return ((op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6
					|| op == 7 || op == 8 || op == 13 || op == 16) ? 4 : 2);
}

int		is_arg_first_char(char *line, int i)
{
	return (line[i] == 'r' || line[i] == '%' ||
		((line[i] == ':' && i < 0 && line[i-1] != '%')||(line[i] == ':' && i == 0))
		|| (line[i] <= '0' && line[i] >= '9'));
}

/************************************************/

int		get_next_argum_index(char *line, int i)
{
	while (line[i] && !IS_COMMENT_CHAR(line[i]))
	{
		if (is_arg_first_char(line, i))
			return (i);
		i++;
	}
	if (IS_COMMENT_CHAR(line[i]))
		return (-1);
	return (-2);
}

int		get_this_arg_size(char *line, int i, int op)
{
	if (line[i] == 'r')
		return (1);
	else if (line[i] == '%')
		return (get_t_dir_size(op));
	else
		return (2);
}

int		get_arguments_size(char *line, int opr)
{
	int i;
	int argums_size;

	argums_size = 0;
	i = -1;
	while (line[++i] && (!IS_SPACE(line[i])))
		;
	if (IS_SPACE(line[i]))
		i++;
	while (line[i] && !IS_COMMENT_CHAR(line[i]))
	{
		argums_size += get_this_arg_size(line, i, opr);
		i = get_next_argum_index(line, i+1);
		if (i < 0)
			break ;
	}
	return (argums_size);
}

int		get_operation_size(t_env *env, char *line)
{
	int i;
	int opr_code;
	int	opr_size;

	opr_size = 1;
	i = get_first_char_index(line);
	opr_code = get_operation_code(&line[i]);
	if (is_args_octet_present(opr_code))
		opr_size++;
	opr_size += get_arguments_size(&line[i], opr_code);
	return (opr_size);
}

void	save_label_position(char *line, int current_bytes, t_env *env)
{
	int i;
	int j;

	j = -1;
	while (IS_SPACE(line[++j]))
		;
	j = i - 1;
	while (line[++i] && line[i] != LABEL_CHAR)
		;
/***************/
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
	while (IS_SPACE(line[i]))
		i++;
	if (is_operation(&line[i]))
		return (i);
	return (0);
}


void	tokenize_data(t_env *env)
{
	t_data *data;
	char *line;
	int		current_bytes;
	int i;

	current_bytes = 0;
	get_next_line(env->src_file, &line);
	env->data->line = line;
	data = env->data;
	while (get_next_line(env->src_file, &line))
	{
		data->next = (t_data *)ft_memalloc(sizeof(t_data));
		data = data->next;
		data->line = line;
		
		if (is_label(line))
		{
			save_label_position(line, current_bytes, env);
			if ((i = is_label_operation_in_same_line(line)) > 0)
				current_bytes += get_operation_size(env, &line[i]);
		}
		else if (is_operation(line))
			current_bytes += get_operation_size(env, line);

		data->current_octets = current_bytes;


	}
}
