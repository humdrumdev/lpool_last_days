#ifndef DO_OP_H

#define DO_OP_H

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

typedef int (*t_operation)(int, int);

int add(int a, int b);
int substract(int a, int b);
int divide(int a, int b);
int modulo(int a, int b);
int multiply(int a, int b);

void ft_putnbr(int nb);
int ft_strlen(char *str);
int ft_atoi(const char *str);
int ft_strncmp(const char *lhs, const char *rhs, size_t count);
int operation_index(char op);
void init_operations(t_operation *ops);
int is_valid_operator(char *op);

#endif