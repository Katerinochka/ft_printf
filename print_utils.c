/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:55:52 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 16:55:57 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_space(int count)
{
	while (count > 0)
	{
		write(1, " ", 1);
		count--;
	}
}

void	print_zero(int count)
{
	while (count > 0)
	{
		write(1, "0", 1);
		count--;
	}
}