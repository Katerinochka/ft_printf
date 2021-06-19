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

typedef struct s_struct
{
    int     accur;
    int     star_space;
    int     star_accur;
    int     count_zero;
    int     space_r;
    int     space_l;
    char    this_type;
}               t_struct;

int     ft_printf(const char *str, ...);

void    ft_putchar(char c);

void    ft_putnbr(int n);

size_t	ft_strlen(const char *str);

void	ft_putstr(char *s, int fd);

int	    print_int(int num, t_struct params);

int	    print_char(char c, t_struct params);

int	    print_str(char *str, t_struct params);

void	print_space(int count);

void	print_zero(int count);

int     ft_putnstr(char *s, int n);

int	    print_p(unsigned long long ptr, t_struct params);

int	    print_x(unsigned int num,char *strx, t_struct params);

#endif