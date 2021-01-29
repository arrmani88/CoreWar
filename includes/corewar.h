/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:57 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 12:46:04 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef COREWAR_H
#define COREWAR_H

#include "../libft/libft.h"
#include "op.h"
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
/***********************/
#include <stdio.h>

#define IS_SPACE(X) (X == ' ' || X == '\t')
#define	IS_COMMENT_CHAR(X) (X == ALT_COMMENT_CHAR || X == COMMENT_CHAR)

typedef struct	s_data
{
	char *line;
	struct s_data *next;
}				t_data;

typedef struct		s_opr
{
	char	*line;
	char	opr_code;
	char	enc_octet;

	int		arg1;
	int		arg2;
	int		arg3;

	char	cast1;
	char	cast2;
	char	cast3;
	
	int		opr_size;
	struct s_opr	*next;

}				t_opr;

typedef struct	s_env
{
	header_t	hdr;
	t_data		*data;
	t_opr		*opr;
	int			src_file;
	int			dst_file;
	int			readed_size;
}				t_env;

short int	two_s_complement_conv(short int n);

int     is_input_correct(char *s);
void	write_initial_data(t_env *env);
void    set_initial_data(t_env *env);
int		get_first_char_index(char *str);
void	tokenize_data(t_env *env);
int		is_operation(char *line);
int		is_empty_line(char *line);
int		is_label(t_env *env, char *str);
int		get_operation_code(char *line);
int		is_arg_first_char(char *line, int i);
void	set_data_in_nodes(t_env *env);
int		is_args_octet_present(int op);
unsigned char	set_args_octet(char *line);



int		get_arguments_size(char *line, int opr);

#endif  