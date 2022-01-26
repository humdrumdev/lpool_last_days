#include "do_op.h"

int do_math(char **av)
{
    int rhs;
    char op;
    t_operation operations[5];
    t_operation operation;

    init_operations(operations);
    op = av[2][0];
    rhs = ft_atoi(av[3]);
    if (rhs == 0 && (op == '/' || op == '%'))
    {
        if (op == '/')
            write(1, "Stop : division by zero\n", 24);
        if (op == '%')
            write(1, "Stop : modulo by zero\n", 22);
        return (0);
    }
    operation = operations[operation_index(op)];
    ft_putnbr((operation(ft_atoi(av[1]), rhs)));
    write(1, "\n", 1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (0);
    if (is_valid_operator(av[2]) == 0)
    {
        write(1, "0\n", 2);
        return (0);
    }
    return (do_math(av));
}