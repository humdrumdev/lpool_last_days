#include "../include/do_op.h"

int ft_usage(void)
{
    write(STDERR_FILENO, USAGE, ft_strlen(USAGE));
    return (1);
}