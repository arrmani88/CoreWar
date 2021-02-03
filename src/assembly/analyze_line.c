/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:18:26 by anel-bou          #+#    #+#             */
/*   Updated: 2021/02/03 10:20:41 by anel-bou         ###   ########.fr       */
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
	if (!get_operation_code(&line[i]))
		return (0);
	while (line[++i] && !IS_SPACE(line[i]))
		;
	if (line[i-1] == LABEL_CHAR)
		return (0);
	return (1);
}

int		is_label(char *str)
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


	// if (is_operation(&str[++i]))
	// 	write_operation(str);
	/*  <<<label followed by operation>>>  */
	return (1);
}
