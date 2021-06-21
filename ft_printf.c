/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroselyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:49:34 by aroselyn          #+#    #+#             */
/*   Updated: 2021/06/10 15:49:36 by aroselyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *flags = "%-0.*\0";
char    *types = "cspdiuX\0";

void	print_struct(t_struct params)
{
	printf("\n*******\n");
	printf("accur:       %d\n", params.accur);
	printf("star_space:  %d\n", params.star_space);
	printf("star_accur:  %d\n", params.star_accur);
	printf("count_zero:  %d\n", params.count_zero);
	printf("space_r:     %d\n", params.space_r);
	printf("space_l:     %d\n", params.space_l);
	printf("type:        %c\n", params.this_type);
	printf("*******\n");
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	char	*rez;

	rez = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!rez)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		rez[i] = s1[i];
		i++;
	}
	free((char *)s1);
	rez[i + j] = s2[j];
	j++;
	rez[i + j] = '\0';
	return (rez);
}

int	ft_atoi_one(char str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	j = 0;
	res = res * 10 + (str - '0');
	return ((int)(res));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int fits(int c)
{
    int my_flag;
    int my_type;
    int i;
   
    i = 0; 
    my_flag = 0;
    while (flags[i])
    {
        if (flags[i] == c)
            my_flag = 1;
        i++;
    }
    i = 0; 
    my_type = 0;
    while (types[i])
    {
        if (types[i] == c)
            my_type = 1;
        i++;
    }
    if (ft_isdigit(c) || my_flag || my_type)
        return (1);
    return (0);
}

char    *get_params(const char *str)
{
    char *params;
    int j;
    
    j = 1;
    params = malloc(1);
    if (str[j] == '%')
        write(1, "%", 1);
    else
    {
        while (fits(str[j]))
        {
            params = ft_strjoin(params, &str[j]);
            j++;
            if (ft_isalpha(str[j]) && !(ft_isalpha(params[ft_strlen(params) - 1])))
			{
				params = ft_strjoin(params, &str[j]);
				break ;
			}
        }
    }
	//printf("[%s]", params);
    return (params);
}

int	stars(t_struct *params)
{
	if (params->star_space)
		params->star_accur = 1;
	else
		params->star_space = 1;
	return (2);
}

int	counts(const char *str, int *count)
{
	int	i;

	i = 1;
	while (ft_isdigit(str[i]))
	{
		*count = *count * 10 + ft_atoi_one(str[i]);
		i++;
	}
	return (i);
}

int	numbers(const char *str, int *count)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		*count = *count * 10 + ft_atoi_one(str[i]);
		i++;
	}
	return (i);
}

t_struct	*struct_init(void)
{
	t_struct	*params;

	params = malloc(sizeof(t_struct));
	params->accur = -1;
	params->star_space = 0;
	params->star_accur = 0;
	params->count_zero = 0;
	params->space_r = 0;
	params->space_l = 0;
	return (params);
}

int	params_parser(const char *str, t_struct *params)
{
    int i;
    
    i = 0;
	*params = *struct_init();
	while (str[i])
	{
		if (str[i] == '*')
			i += stars(params);
		else if (str[i] == '-')
			i += counts(&str[i], &params->space_l);
		else if (str[i] == '0')
			if (str[i + 1] == '-')
				i += counts(&str[i], &params->space_l);
			else
				i += counts(&str[i], &params->count_zero);
		else if (str[i] == '.')
			i += counts(&str[i], &params->accur);
		else if ((str[i] != '0' && ft_isdigit(str[i])))
			i += numbers(&str[i], &params->space_l);
		else
			params->this_type = str[i++];
	}
	//print_struct(*params);
	return (i);
}

int	definition_type(t_struct params)//, va_list types)
{
	int	count;
	
	count = 0;
	if (params.this_type == 'd' || params.this_type == 'i')
		count += print_int(11, params);
	else if (params.this_type == 'c')
		count += print_char('p', params);
	else if (params.this_type == 's')
		count += print_str("qwerty", params);
	else if (params.this_type == 'x')
		count += print_x((unsigned int)4294967295, "0123456789abcdef", params);
	else if (params.this_type == 'X')
		count += print_x((unsigned int)232, "0123456789ABCDEF", params);
	else if (params.this_type == 'p')
		count += print_p((unsigned long)NULL, "0123456789abcdef", params);
	else if (params.this_type == 'u')
		count += print_u(-5, params);
	return (count);
}

int ft_printf(const char *str, ...)
{
    int         i;
    t_struct    params;
	va_list		types;
    
    i = 0;
	va_start(types, str);
    while (str[i])
    {
        if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
        else
		{
			i += params_parser(get_params(&str[i]), &params) + 1;
			//print_struct(params);
			definition_type(params);
		}
    }
	return (0);
}
