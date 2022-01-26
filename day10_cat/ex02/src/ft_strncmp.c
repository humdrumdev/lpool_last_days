#include <stddef.h>

int ft_strncmp(const char *lhs, const char *rhs, size_t count)
{
    if (!count)
        return (0);
    while (*lhs && count > 1)
    {
        if (*lhs != *rhs)
            break;
        lhs++;
        rhs++;
        count--;
    }
    return (*(const unsigned char *)lhs - *(const unsigned char *)rhs);
}