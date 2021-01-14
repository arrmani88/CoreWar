/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_s_complement_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:01:34 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/14 19:00:50 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int			get_first_true_bit(short int n)
{
	int			firsttruebit;
	int			shf;
	
	shf = 1;
	firsttruebit = 0;
	while (shf <= 32768)
	{
		firsttruebit++;
		if (n & shf)
			break ;
		shf = shf << 1;
	}
	return (firsttruebit);
}

short int	two_s_complement_conv(short int n)
{
	short int	res;
	int			firsttruebit;

	firsttruebit = get_first_true_bit(n) ;
	res = 0;
	while (!(res & 32768))
	{
		if (firsttruebit-- >= 0)
		{
			res = res | 1;
			printf("1");
			// firsttruebit--;
		}
		else 
			printf("0");
		res  = res << 1;
	}
	printf("\n....%d....\n", n^res);
	return (n ^ res);
}
