#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_struct
{
    int     width;
    int     accur;
    int     star_space;
    int     star_accur;
    int     count_zero;
    int     count_space;
    char    this_type[2];
}               t_struct;

#endif