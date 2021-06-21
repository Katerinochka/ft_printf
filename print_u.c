/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:25:57 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/21 16:25:59 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(unsigned int num, t_struct params)
{
	int	len;
	int width;
	int accure;
	int	zeros;
	int	spaces;

	len = len_num(num);
	width = params.space_l;
	accure = params.accur;
	zeros = accure - len;
	spaces = width - zeros - len;
	if (!(accure == 0 && num == 0))
	{
		print_space(spaces);
		print_zero(zeros);
		ft_putnbr(num);
		if (params.space_r)
			print_space(params.space_r - len);
		return (len);
	}
	return (1);
}