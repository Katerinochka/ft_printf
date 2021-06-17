/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:04:57 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 16:04:59 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, t_struct params)
{
	if (params.space_r)
		print_space(params.space_r - 1);
	ft_putchar(c);
	if (params.space_l)
		print_space(params.space_l - 1);
	return (1);
}
