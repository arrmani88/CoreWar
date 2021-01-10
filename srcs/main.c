/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/10 19:00:44 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

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


int	convertFile(char *s)
{
	int srcFile;
	int dstFile;
	
	if ((srcFile = open(s, O_RDONLY)) == -1)
		return (-1);
	dstFile = open(getFileName(s), O_APPEND | O_CREAT | O_RDWR | O_TRUNC, 0644);
	// printf("src={%d}\ndst={%d}\n", srcFile, dstFile);

	return (0);
}

int     main(int ac, char **av)
{
	if (ac > 1) 
	{
		if (!isInputCorrect(av[ac - 1]) || (convertFile(av[ac - 1]) == -1))
			return (0);
	}
	return (0);
}




