#include "../includes/tail.h"

int valid_arg(char *candidate, char *successor, const char *arg, int *bytes)
{
    size_t len;

    len = ft_strlen(arg);
    if (ft_strncmp(candidate, arg, len) == 0)
    {
        if (len == ft_strlen(candidate))
        {
            if (!successor)
                return (-3);
            return (valid_successor(successor, bytes));
        }
        return (2 * valid_successor(candidate + len, bytes));
    }
    if (candidate[0] == '-')
        return (-4);
    return (0);
}

void on_success(int *drop, int *j, int ac, t_err_arg *_res)
{
    drop[*j] = 0;
    _res->code = 0;
    if (*j == ac - 1)
        _res->code = 1;
    _res->index = 0;
    if (ac == 1)
        _res->bytes = -4;
}
void on_valid_arg(int is_valid, int *i, int *j, int *drop)
{
    if (is_valid == 1)
    {
        drop[(*j)++] = (*i)++;
        drop[(*j)++] = *i;
    }
    if (is_valid == 2)
        drop[(*j)++] = (*i);
}

t_err_arg get_valid_arg(int ac, char **av, const char *arg, int *drop)
{
    int i;
    int j;
    t_err_arg res;
    int is_valid;

    i = 0;
    j = 0;
    res.bytes = MAX_BUF_SIZE;
    while (++i < ac)
    {
        if (i == (ac - 1))
            is_valid = valid_arg(av[i], NULL, arg, &(res.bytes));
        else
            is_valid = valid_arg(av[i], av[i + 1], arg, &(res.bytes));
        if (is_valid < 0)
        {
            res.code = is_valid;
            res.index = i;
            return (res);
        }
        on_valid_arg(is_valid, &i, &j, drop);
    }
    on_success(drop, &j, ac, &res);
    return (res);
}

t_result valid_input(int ac, char **av, char *arg)
{
    t_result result;

    result.status = get_valid_arg(ac, av, arg, result.idxtodrop);
    return (result);
}