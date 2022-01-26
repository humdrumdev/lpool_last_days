int is_space(char c)
{
    int cnd;
    cnd = (c == ' ') || (c == '\n') || (c == '\t');
    return (cnd || (c == '\v') || (c == '\r') || (c == '\f'));
}

int is_sign(char c)
{
    if (c == '+')
        return (1);
    if (c == '-')
        return (-1);
    return (0);
}

int is_num(char c)
{
    return ((c >= '0') && (c <= '9'));
}

long to_num(const char *str)
{
    int i;
    long nb;

    i = 0;
    nb = 0;
    while (is_num(str[i]))
    {
        nb = nb * 10 + str[i] - '0';
        if (nb >= 2147483647)
            return (nb);
        i++;
    }
    return (nb);
}

int ft_atoi(const char *str)
{
    int i;
    int issign;
    int sign;

    i = 0;
    while (is_space(str[i]))
        i++;
    sign = 1;
    issign = 1;
    while (issign)
    {
        issign = is_sign(str[i]);
        if (issign)
        {
            i++;
            sign *= issign;
        }
    }
    return (sign * to_num(str + i));
}