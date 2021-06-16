/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include "ft_printf.h"

char    *flags = "%-0.*\0";
char    *types = "cspdiuX\0";

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*((char *)str + n) != '\0')
		n++;
	return (n);
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
	free(s1);
	rez[i + j] = s2[j];
	j++;
	rez[i + j] = '\0';
	return (rez);
}

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

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	res;
	int	minus;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus = -1;
	else
		minus = 1;
	if (minus == -1 || str[i] == '+')
		i++;
	res = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * minus));
}

int	ft_atoi_one(const char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	j = 0;
	res = res * 10 + (str[i] - '0');
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

char    *get_params(const char *str, int *i)
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
            if (ft_isalpha(str[j]))
                break ;
        }
    }
    *i += j;
    return (params);
}

void    params_parser(char *str, char this_type, t_struct params)
{
    int i;
    
    i = 0;
    if (str[i] == '*')
    {
        i++;
        params.star_space = 1;
    }
    if (str[i] == '-')
    {
        i++;
        if (str[i] == '0')
            i++;
        params.count_space = 0;
        while(ft_isdigit(str[i]))
        {
            params.count_space = params.count_space * 10 + ft_atoi_one(str[i]);
            i++;
        }
    }
    if (str[i] == '0')
    {
        i++;
        params.count_zero = 0;
        if (str[i] != '-')
        {
            while (ft_isdigit(str[i]))
            {
                params.count_zero = params.count * 10 + ft_atoi_one(str[i]);
                i++;
            }
        }
    }
    if (str[i] == '.')
    {
        i++;
        params.accur = 0;
        while (ft_isdigit(str[i]))
        {
            params.accur = params.accur * 10 + ft_atoi_one(str[i]);
            i++;
        }
    }
}

int ft_printf(const char *str, int d)
{
    int         i;
    char        this_type;
    t_struct    params;
    
    i = 0;
    while (str[i])
    {
        if (str[i] != '%')
            write(1, &str[i], 1);
        else
        {
            printf("\n%s\n",get_params(&str[i], &i));
            this_type = str[i];
            printf("\n%c\n", this_type);
        }
        i++;
    }
}

int main()
{
    /*printf("0----%d-\n", 42);
    printf("1----%1d-\n", 42);
    printf("2----%2d-\n", 42);
    printf("3----%4d-\n", 42);
    printf("4----%-2d-\n", 42);
    printf("5----%-4d-\n", 42);
    printf("6----%01d-\n", 42);
    printf("7----%04d-\n", 42);
    printf("8----%0-4d-\n", 42);
    printf("9----%-04d-\n", 42);
    printf("10---%.1d-\n", 42);
    printf("11---%.4d-\n", 42);
    printf("12---%4.d-\n", 42);
    printf("13---%.3f-\n", 42.1234567);
    printf("14---%7.3f-\n", 42.1234567);
    printf("15---%2.3f-\n", 42.1234567);
    printf("16---%*.3f-\n", 7, 42.1234567);
    printf("17---%7.*f-\n", 4, 42.1234567);
    printf("18---%*.*f-\n", 7, 3, 42.1234567);
    printf("----------------");*/
    ft_printf("0----%18ctyu-\n", 12);
    return 0;
}


