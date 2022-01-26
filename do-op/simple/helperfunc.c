#include "do_op.h"

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '%' || c == '*');
}

int is_valid_operator(char *op)
{
    int len;

    len = ft_strlen(op);
    if (ft_strncmp(op, "plus", len) == 0)
        return (op[0] = '+');
    if (ft_strncmp(op, "minus", len) == 0)
        return (op[0] = '-');
    if (ft_strncmp(op, "modulo", len) == 0)
        return (op[0] = '%');
    if (ft_strncmp(op, "divide", len) == 0)
        return (op[0] = '/');
    if (ft_strncmp(op, "multiply", len) == 0)
        return (op[0] = '*');
    if (len == 1)
        return (is_operator(op[0]));
    return (0);
}

void init_operations(t_operation *ops)
{
    ops[0] = add;
    ops[1] = substract;
    ops[2] = divide;
    ops[3] = modulo;
    ops[4] = multiply;
}

int operation_index(char op)
{
    int i;
    char *ops;

    ops = "+-/%*";
    i = 0;
    while (i < 5)
    {
        if (op == ops[i])
            return (i);
        i++;
    }
    return (-1);
}