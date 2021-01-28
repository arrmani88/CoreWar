/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:57 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/28 09:24:12 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef COREWAR_H
#define COREWAR_H

#include "../libft/libft.h"
#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#include <stdio.h>

typedef struct	s_op
{
	char *line;
	/*********/
	struct s_op	*next;
}				t_op;

typedef struct	s_label
{
	t_op			*op;
	struct s_label	*next;
}				t_label;

typedef struct	s_env
{
	header_t	hdr;
	t_label		*label;
    int			src_file;
	int			dst_file;
}				t_env;

short int	two_s_complement_conv(short int n);

int     is_input_correct(char *s);
void    convert_file(t_env *env);
void    set_champ_name(t_env *env, char *str);
void	write_initial_data(t_env *env);
void    set_initial_data(t_env *env);
void	write_operation(char *line);
int		get_first_char_index(char *str);


#endif  