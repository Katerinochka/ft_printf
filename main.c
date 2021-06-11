/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

char    *flags = "%-0.*\0";
char    *types = "cspdiuX\0";

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
	res = 0;
	j = 0;
	res = res * 10 + (str[i] - '0');
	return ((int)(res));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void parser(const char *str, int *i, int d)
{
    int j;
    int width;

    j = 1;
    width = 0;
    if (str[j] == '%')
        write(1, "%", 1);
    else
        while (ft_isdigit(str[j]))
        {
            width = width*10 + ft_atoi(&str[j]);
            j++;
        }
    *i += j;
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
    int j;
    
    j = 1;
    if (str[j] == '%')
    {
        write(1, "%", 1);
        return (NULL);
    }
    else
        while (fits(str[j]))
        {
            
            j++;
        }
    *i += j;
}

int ft_printf(const char *str, int d)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] != '%')
            write(1, &str[i], 1);
        else
            parser(&str[i], &i, d);
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
    ft_printf("0----%8d-\n", 12);
    return 0;
}
