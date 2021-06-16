/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:49:45 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/10 15:49:47 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>

int ft_printf(const char *str, ...);

typedef struct s_struct
{
    int     accur;
    int     star_space;
    int     star_accur;
    int     count_zero;
    int     count_space;
    char    *this_type;
}               t_struct;

#endif