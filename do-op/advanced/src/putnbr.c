#include "../include/do_op.h"

void ft_edge_cases(int nb)
{
    if (nb == 0)
    {
        write(1, "0", 1);
    }
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
    }
}

void ft_putnbr(int nb)
{
    char c;

    if ((nb == 0) || (nb == -2147483648))
    {
        ft_edge_cases(nb);
        return;
    }
    if (nb < 0)
    {
        nb *= -1;
        write(1, "-", 1);
    }
    if (nb < 10)
    {
        c = (char)(nb + 48);
        write(1, &c, 1);
        return;
    }
    ft_putnbr(nb / 10);
    c = (char)((nb % 10) + 48);
    write(1, &c, 1);
}