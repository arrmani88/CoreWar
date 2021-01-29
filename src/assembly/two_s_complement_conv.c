/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_s_complement_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:01:34 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/29 09:12:44 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int			get_first_true_bit(short int n)
{
	int			firsttruebit;
	int			shf;
	
	shf = 1;
	firsttruebit = 0;
	while (shf <= 0x8000)
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
	unsigned short int	res;
	int			true_bits;

	true_bits = 16 - get_first_true_bit(n);
	res = 0;
	while (!(res & 0x8000))
	{
		if (true_bits-- > 0)
			res = res | 1;
		else 
		res  = res << 1;
	}
	return (n ^ res);
}
