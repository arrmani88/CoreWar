/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_name_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:14:49 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 14:49:53 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void    set_champ_name(t_env *env, char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i] && str[i] != '"')
		;
	j = i;
	++i;
	while (str[++j] && str[j] != '"')
		;
	ft_strncpy(env->hdr.prog_name, &str[i], j - i);
}

void	set_champ_comment(t_env *env, char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i] && str[i] != '"')
		;
	j = i;
	++i;
	while (str[++j] && str[j] != '"')
		;
	ft_strncpy(env->hdr.comment , &str[i], j - i);
}

void    set_initial_data(t_env *env)
{
	char *line;

	env->hdr.magic = env->hdr.magic = ((COREWAR_EXEC_MAGIC&0xff)<<24) |
			(COREWAR_EXEC_MAGIC<<8&0xff0000) | (COREWAR_EXEC_MAGIC>>8&0xff00);
	while(get_next_line(env->src_file, &line) > 0)
	{
		if (str_begins_with(line, NAME_CMD_STRING))
			set_champ_name(env, line);
		else if (str_begins_with(line, COMMENT_CMD_STRING))
		{
			set_champ_comment(env, line);
			break ;
		}
	}
}

void	write_initial_data(t_env *env)
{
	int null;

	null = 0;
	write(env->dst_file, &(env->hdr.magic), 4);
	write(env->dst_file, &(env->hdr.prog_name), PROG_NAME_LENGTH);
	write(env->dst_file, &null, 4);
	write(env->dst_file, &null, 4); /*temporaire dial executable size*/
	write(env->dst_file, &(env->hdr.comment), COMMENT_LENGTH); /* flheader dayrin CMNT_LEN+1 tanchof 3lach daroha */
	write(env->dst_file, &null, 4);
}
