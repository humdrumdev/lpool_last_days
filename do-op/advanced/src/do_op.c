#include "../ft_opp.h"
#include "../include/do_op.h"

int is_valid_operator(char *op)
{
    int len;
    int i;

    len = ft_strlen(op);
    i = 0;
    while (g_opptab[i].op[0])
    {
        if (ft_strncmp(op, g_opptab[i].op, len) == 0)
            return (i);
        i++;
    }
    return (-1);
}

int do_math(char **av, int index)
{
    int rhs;
    t_opp op;
    t_operation f;

    op = g_opptab[index];
    rhs = ft_atoi(av[3]);
    f = (op.func);
    if (rhs == 0 && (f == &ft_div || f == &ft_mod))
    {
        if (f == &ft_div)
            write(1, "Stop : division by zero\n", 24);
        else
            write(1, "Stop : modulo by zero\n", 22);
        return (0);
    }
    ft_putnbr((f(ft_atoi(av[1]), rhs)));
    write(1, "\n", 1);
    return (0);
}

int main(int ac, char **av)
{
    int op_index;

    if (ac != 4)
        return (0);
    if ((op_index = is_valid_operator(av[2])) == -1)
        return (ft_usage());
    return (do_math(av, op_index));
}