/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:35:43 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 17:35:48 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long ptr, char *strx, t_struct params)
{
	char	rez[20];
	int		i;
	int		len;

	i = 0;
	while (ptr)
	{
		rez[i++] = strx[ptr % 16];
		ptr = ptr / 16;
	}
	len = ft_strlen(rez);
	if (params.space_r)
		print_space(params.space_r - len);
	ft_putnstr("0x", 2);
	if (len == 0)
		ft_putchar('0');
	while (i >= 0)
		ft_putchar(rez[--i]);
	if (params.space_l)
		print_space(params.space_l - len);
	return (1);
}