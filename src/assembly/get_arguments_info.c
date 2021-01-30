/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:24:14 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/30 11:46:50 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		is_args_octet_present(int op)
{
	return (op != 0x1 && op != 0x9 && op != 0xc && op != 0xf);
}

int		is_arg_first_char(char *line, int i)
{
	return (line[i] == 'r' || line[i] == '%' ||
		((line[i] == ':' && i < 0 && line[i-1] != '%')||(line[i] == ':' && i == 0))
		|| (line[i] <= '0' && line[i] >= '9'));
}

int		get_t_dir_size(int op)
{
	return ((op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6
					|| op == 7 || op == 8 || op == 13 || op == 16) ? 4 : 2);
}

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

int		get_all_arguments_size(char *line, int opr)
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

int		get_this_arg_size(char *line, int i, int op)
{
	if (line[i] == 'r')
		return (1);
	else if (line[i] == '%')
		return (get_t_dir_size(op));
	else
		return (2);
}

int		get_current_argument_code(char *line)
{
	if (line[0] == 'r')
		return (0b01);
	else if (line[0] == '%')
		return (0b10);
	else
		return (0b11);
}

