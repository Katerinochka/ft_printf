/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:02:43 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 14:02:45 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max3(int a, int b, int c)
{
	int	max;

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return (max);
}

int	print_int(int num, t_struct params)
{
	int	len;
	int	zeros;
	int	spaces;
	int	ac;

	len = len_num(num);
	if (num < 0)
		len++;
	if (params.accur || num)
	{
		ac = params.accur;
		if (params.accur == -1)
			ac = 0;
		printf("[%d]", ac);
		zeros = ac - len;
		spaces = params.space_l - zeros - len;
		print_space(spaces);
		print_zero(zeros);
		ft_putnbr(num);
		if (params.space_r)
			print_space(params.space_r - len);
		//return (max3(zeros, spaces, len));
		return (len);
	}
	return (1);
}