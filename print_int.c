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

int	len_num(int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /=10;
		len++;
	}
	return (len);
}

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
	int width;
	int accure;
	int	zeros;
	int	spaces;

	len = len_num(num);
	if (num < 0)
		len++;
	width = params.space_l;
	accure = params.accur;
	zeros = accure - len;
	spaces = width - zeros - len;
	if (!(accure == 0 && num == 0))
	{
		print_space(spaces);
		print_zero(zeros);
		if (num < 0)
			ft_putchar('-');
		ft_putnbr(num);
		if (params.space_r)
			print_space(params.space_r - len);
		//return (max3(zeros, spaces, len));
		return (len);
	}
	return (1);
}