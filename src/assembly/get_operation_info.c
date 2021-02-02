/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operation_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:22:36 by anel-bou          #+#    #+#             */
/*   Updated: 2021/02/02 12:20:10 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"


int		get_first_char_index(char *str)
{
	int i;

	i = -1;
	while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
		;
	return (i);
}

int		get_operation_len(char *line)
{
	int		op_len;

	op_len = 0;
	(!op_len && str_begins_with(line, "lldi")) ? op_len = 4 : 0;
	(!op_len && str_begins_with(line, "lld")) ? op_len = 3 : 0;
	(!op_len && str_begins_with(line, "ldi")) ? op_len = 3 : 0;
	(!op_len && str_begins_with(line, "ld")) ? op_len = 2 : 0;
	(!op_len && str_begins_with(line, "sti")) ? op_len = 3 : 0;
	(!op_len && str_begins_with(line, "st")) ? op_len = 2 : 0;
	(!op_len && str_begins_with(line, "live")) ? op_len = 4: 0;
	(!op_len && str_begins_with(line, "add")) ? op_len = 3 : 0;
	(!op_len && str_begins_with(line, "sub")) ? op_len = 3: 0;
	(!op_len && str_begins_with(line, "and")) ? op_len = 3: 0;
	(!op_len && str_begins_with(line, "or")) ? op_len = 2: 0;
	(!op_len && str_begins_with(line, "xor")) ? op_len = 3 : 0;
	(!op_len && str_begins_with(line, "zjmp")) ? op_len = 4 : 0;
	(!op_len && str_begins_with(line, "fork")) ? op_len = 4: 0;
	(!op_len && str_begins_with(line, "lfork")) ? op_len = 5: 0;
	(!op_len && str_begins_with(line, "aff")) ? op_len = 3 : 0;
	return (op_len);
}

int		get_operation_code(char *line)
{
	int		op_code;

	op_code = 0;
	(!op_code && str_begins_with(line, "lldi")) ? op_code = 0x0e : 0;
	(!op_code && str_begins_with(line, "lld")) ? op_code = 0x0d : 0;
	(!op_code && str_begins_with(line, "ldi")) ? op_code = 0x0a : 0;
	(!op_code && str_begins_with(line, "ld")) ? op_code = 0x02 : 0;
	(!op_code && str_begins_with(line, "sti")) ? op_code = 0x0b : 0;
	(!op_code && str_begins_with(line, "st")) ? op_code = 0x03 : 0;
	(!op_code && str_begins_with(line, "live")) ? op_code = 0x01 : 0;
	(!op_code && str_begins_with(line, "add")) ? op_code = 0x04 : 0;
	(!op_code && str_begins_with(line, "sub")) ? op_code = 0x05 : 0;
	(!op_code && str_begins_with(line, "and")) ? op_code = 0x06 : 0;
	(!op_code && str_begins_with(line, "or")) ? op_code = 0x07 : 0;
	(!op_code && str_begins_with(line, "xor")) ? op_code = 0x08 : 0;
	(!op_code && str_begins_with(line, "zjmp")) ? op_code = 0x09 : 0;
	(!op_code && str_begins_with(line, "fork")) ? op_code = 0x0c : 0;
	(!op_code && str_begins_with(line, "lfork")) ? op_code = 0x0f : 0;
	(!op_code && str_begins_with(line, "aff")) ? op_code =  0x010: 0;
	return (op_code);
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
	opr_size += get_all_arguments_size(&line[i], opr_code);
	return (opr_size);
}
