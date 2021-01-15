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

int		get_first_char_index(char *str)
{
	int i;

	i = -1;
	while (str[++i] && (str[i] == ' ' || str[i] == '\t'))
		;
	return (i);
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
		write_operation(env, str);
		
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

int		get_opertation_code(char *line)
{
	int		op_code;

	op_code = 0;
	(!op_code && str_begins_with(line, "live")) ? op_code = 0x01 : 0;
	(!op_code && str_begins_with(line, "ld")) ? op_code = 0x02 : 0;
	(!op_code && str_begins_with(line, "st")) ? op_code = 0x03 : 0;
	(!op_code && str_begins_with(line, "add")) ? op_code = 0x04 : 0;
	(!op_code && str_begins_with(line, "sub")) ? op_code = 0x05 : 0;
	(!op_code && str_begins_with(line, "and")) ? op_code = 0x06 : 0;
	(!op_code && str_begins_with(line, "or")) ? op_code = 0x07 : 0;
	(!op_code && str_begins_with(line, "xor")) ? op_code = 0x08 : 0;
	(!op_code && str_begins_with(line, "zjmp")) ? op_code = 0x09 : 0;
	(!op_code && str_begins_with(line, "ldi")) ? op_code = 0x0a : 0;
	(!op_code && str_begins_with(line, "sti")) ? op_code = 0x0b : 0;
	(!op_code && str_begins_with(line, "fork")) ? op_code = 0x0c : 0;
	(!op_code && str_begins_with(line, "lld")) ? op_code = 0x0d : 0;
	(!op_code && str_begins_with(line, "lldi")) ? op_code = 0x0e : 0;
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
	if (line[i] == 'r')
		return (0b01);
	else if (line[i] == '%')
		return (0b10);
	else
		return (0b11);
}

char	set_args_octet(char *line)
{
	char	oct;
	int		i;
	int		shf;

	oct = 0;
	i = -1;
	shf = 6;
	while (line[++i] && shf)
	{
		if (line[i] == 'r' || line[i] == '%' || line[i] ==         ) /*l7arf lowwl dial argum*/
			oct = oct & (get_current_argument_code(&line[i]) << shf);
		shf -= 2;
	}


}

void	write_operation(t_env *env, char *line)
{
	int		i;
	int		op_code;
	char	args_oct;

	args_oct = 1;
	i = get_first_char_index(line);
	op_code = get_operation_code(&line[i]);
	if (is_args_octet_present(op_code))
		args_oct = set_args_octet(&line[i]);
	


	

	
	return ;
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
				write_operation(env, line);
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