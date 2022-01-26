#ifndef FT_OPP_H
#define FT_OPP_H

#include "./include/opps.h"

t_opp g_opptab[] =
    {
        {"+", &ft_add},
        {"-", &ft_sub},
        {"*", &ft_mul},
        {"/", &ft_div},
        {"%", &ft_mod},
        {"", &ft_usage}};

#endif