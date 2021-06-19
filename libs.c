/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:05:48 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/17 14:05:50 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	  ft_putchar(48 + n);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*((char *)str + n) != '\0')
		n++;
	return (n);
}

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

int	ft_putnstr(char *s, int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i - 1);
}