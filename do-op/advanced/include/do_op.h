#ifndef DO_OP_H

#define DO_OP_H

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef int (*t_operation)(int, int);

#define USAGE "error : only [ - + * / % ] are accepted.\n"

void ft_putnbr(int nb);
int ft_strlen(char *str);
int ft_atoi(const char *str);
int ft_strncmp(const char *lhs, const char *rhs, size_t count);
int is_valid_operator(char *op);

#endif