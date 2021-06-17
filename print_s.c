/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:16:45 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 17:16:47 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_struct params)
{
	if (params.space_r)
		print_space(params.space_r - ft_strlen(str));
	ft_putstr(str, 1);
	if (params.space_l)
		print_space(params.space_l - ft_strlen(str));
	return (ft_strlen(str));
}