/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:27:56 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/27 15:13:43 by anel-bou         ###   ########.fr       */
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

int		is_args_octet_present(int op)
{
	return (op != 0x1 && op != 0x9 && op != 0xc && op != 0xf);
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
		// printf("|%d|", i);
		if (line[i] == 'r' || line[i] == '%' ||
				((line[i] == ':' && i < 0 && line[i-1] != '%')
				|| (line[i] == ':' && i == 0)) ||
				(line[i] <= '0' && line[i] >= '9'))
		{
			oct = oct | (get_current_argument_code(&line[i]) << shf);
			shf -= 2;
		}
	}
	return (oct);
}

void	write_operation(char *line)
{
	int				i;
	int				op_code;
	unsigned char	args_oct;

	args_oct = 0;
	i = get_first_char_index(line);
	op_code = get_operation_code(&line[i]);
	if (is_args_octet_present(op_code))
		args_oct = set_args_octet(&line[i]);
	printf("\nline=[%s]\nop=[%x] oct=[%u]\n",line, op_code, args_oct);

}