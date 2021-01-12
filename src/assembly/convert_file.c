/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:27:56 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/12 19:49:09 by anel-bou         ###   ########.fr       */
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
    while (str[++j] && str[i] != '"')
        ;
    
}

void    convert_file(t_env *env)
{
    char *line;
    
    while(get_next_line(env->src_file, &line))
    {
        if (str_begins_with(line, ".name"))
            set_champ_name(env, line);
    }
}