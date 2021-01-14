/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_s_complement_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:01:34 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/14 18:10:45 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int			get_first_true_bit(short int n)
{
	int			firsttruebit;
	int			shf;
	
	shf = 1;
	firsttruebit = 0;
	while (shf <= 128)
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

	firsttruebit = ((n == 0) ? 0 : get_first_true_bit(n));
	res = 0;
	while (!(res & 128))
	{
		if (firsttruebit >= 0)
		{
			res = res | 1;
			printf("1");
			firsttruebit--;
		}
		else 
			printf("0");
		res  = res << 1;
	}
	
	printf("\n....%d....\n", res);
	return (0);
}
