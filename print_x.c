/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:31:27 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/19 14:31:33 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int num, char *strx, t_struct params)
{
	char	rez[9];
	int		i;
	int		len;

	i = 0;
	while (num)
	{
		rez[i] = strx[num % 16];
		num = num / 16;
		i++;
	}
	len = ft_strlen(rez);
	if (params.space_r)
		print_space(params.space_r - len);
	while (i >= 0)
	{
		i--;
		ft_putchar(rez[i]);
	}
	if (params.space_l)
		print_space(params.space_l - len);
	return (len);
}