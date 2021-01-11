/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/11 19:38:34 by anel-bou         ###   ########.fr       */
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

void	writeInFile(int fd, char *txt)
{
	int x;
	lseek(fd, 0, SEEK_END);
	x = write(fd, txt, sizeof(char) * 3);
	// printf("(%d)->(%d)\n", fd, x);
}
// 00ea83f3
void	writeHeaderNameNullSize(int fd)
{
	char		null[4];
	header_t	hdr;
	int			i;
	int			execSize;
	
	i = -1;
	hdr.magic = (COREWAR_EXEC_MAGIC<<24&0xff000000) | (COREWAR_EXEC_MAGIC<<8&0xff0000) | (COREWAR_EXEC_MAGIC>>8&0xff00);
	while (++i <= PROG_NAME_LENGTH)
		hdr.prog_name[i] = 0;
	ft_strcpy(hdr.prog_name, "nVnCIBLE..................:");
	i = -1;
	while (++i < 4)
		null[i] = 0;
	execSize = lseek(fd, 0, )
	write(fd, &(hdr.magic), 4);
	write(fd, &(hdr.prog_name), PROG_NAME_LENGTH);
	write(fd, &null, 4);
}

int	convertFile(char *s)
{
	int srcFile;
	int dstFile;
	
	if ((srcFile = open(s, O_RDONLY)) == -1)
		return (-1);
	dstFile = open(getFileName(s), O_WRONLY | O_CREAT | O_TRUNC , 0644);
	writeHeaderNameNullSize(dstFile);
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
