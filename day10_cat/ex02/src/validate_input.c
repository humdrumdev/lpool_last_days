#include "../includes/tail.h"

int valid_successor(char *successor, int *bytes)
{
    *bytes = ft_atoi(successor);
    while (*successor == ' ')
        successor++;
    if (*successor == '\0')
        return (-1);
    while (*successor)
    {
        if (!is_num(*successor))
            return (-1);
        successor++;
    }
    return (1);
}

t_result validate_input(int ac, char **av, char *arg)
{
    t_result result;

    result = valid_input(ac, av, arg);
    if (result.status.code < 0)
    {
        handle_input_errors(result.status.code, result.status.index, av, arg);
        return (result);
    }
    result.status.index = count_files(result.idxtodrop);
    if (result.status.bytes == MAX_BUF_SIZE)
        result.status.bytes = -1;
    return (result);
}

void handle_input_errors(int error_code, int argidx, char **av, char *arg)
{
    int len;

    len = ft_strlen(arg);
    if (error_code == -3)
        write(STDERR_FILENO, MISSIN_ARG, ft_strlen(MISSIN_ARG));
    else if (error_code == -4)
        logerr(INVALID_OP, INVALID_OP_P, av[argidx]);
    else if (error_code == -2)
        logerr(INVALID_NUM, "’\n", av[argidx] + len);
    else
        logerr(INVALID_NUM, "’\n", av[argidx + 1]);
}

int count_files(int *indices)
{
    int j;

    j = 0;
    while (indices[j] != 0)
        j++;
    return (j);
}