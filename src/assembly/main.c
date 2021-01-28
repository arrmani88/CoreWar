/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/28 19:40:26 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	initialize_data(t_env **env)
{
	(*env) = (t_env *)ft_memalloc(sizeof(t_env));
	(*env)->data = (t_data *)ft_memalloc(sizeof(t_data));
}

int     main(int ac, char **av)
{
	t_env *env;

	if (ac > 1)
	{
		initialize_data(&env);
		convert_file(env);
	}
	return (0);
}




















/************************************/
int     getLastDotIndex(char *s)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == '.')
			j = i;
		i++;
	}
	return (j);
}

char *getFileName(char *s)
{
	int lastDot;
	char *fileName;

	fileName = NULL;
	lastDot = getLastDotIndex(s);
	fileName = ft_strjoin(ft_strsub(s, 0, getLastDotIndex(s)), ".cor");
	return (fileName);
}
	
int	create_file(char *s, t_env *env)
{
	char *exec_name;

	if ((env->src_file = open(s, O_RDONLY)) == -1)
	{
		ft_putendl_fd("unable to open this file", 2);
		return (-1);
	}
	exec_name = getFileName(s);
	ft_putstr("Writing output program to ");
	ft_putstr(exec_name);
	ft_putendl(" ...");
	env->dst_file = open(exec_name, O_WRONLY | O_CREAT | O_TRUNC , 0644);
	return (0);
}



	// printf("# %d #\n", (unsigned short int)-19);
/**************************************************************/

// void	write_beginning_data(t_env *env)
// {
// 	int			i;
// 	int			execSize;

// 	env->hdr.magic = ((COREWAR_EXEC_MAGIC&0xff)<<24) |
// 			(COREWAR_EXEC_MAGIC<<8&0xff0000) | (COREWAR_EXEC_MAGIC>>8&0xff00);
// 	i = -1;
// 	while (++i <= PROG_NAME_LENGTH)
// 		env->hdr.prog_name[i] = 0;
// 	ft_strcpy(env->hdr.prog_name, "nVnCIBLE,,,,,,,,,,,,,,,,,,,");

// 	env->hdr.prog_size = lseek(env->src_file, 0, SEEK_END);

// 	i = -1;
// 	while (++i < COMMENT_LENGTH + 1)
// 		env->hdr.comment[i] = 0;
// 	ft_strcpy(env->hdr.comment, "ara berrrra33333");

// 	write(env->dst_file, &(env->hdr.magic), 4);
// 	write(env->dst_file, &(env->hdr.prog_name), PROG_NAME_LENGTH);
// 	write(env->dst_file, "\0", 4);
// 	write(env->dst_file, &(env->hdr.prog_size), 4);
// 	write(env->dst_file, &(env->hdr.comment), COMMENT_LENGTH); /* flheader dayrin CMNT_LEN+1 tanchof 3lach daroha */
// 	write(env->dst_file, "\0", 4);
// }