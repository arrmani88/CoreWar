/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:26:35 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/10 12:35:39 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
    
    lastDot = getLastDotIndex(s);
    return (NULL);
}

// void    convertFile(char *s)
// {
//     createFile(getFileName(s));
// }

int     main(int ac, char **av)
{
    if (ac > 1) 
    {
        if (!isInputCorrect(av[ac - 1]))
            return (0);
    }
    return (0);
}





        // convertFile(av[ac - 1]);
    // printf("*%d*\n", getLastDotIndex(av[ac - 1]));