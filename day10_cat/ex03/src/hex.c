#include "../includes/hexdump.h"

int write_hexcharC(char c, char *new, int index)
{
    char *hex;

    hex = chartohex(c, "0123456789abcdef");
    if (!hex)
        return (-1);
    new[index++] = hex[0];
    new[index++] = hex[1];
    new[index++] = ' ';
    free(hex);
    return (0);
}

int write_hexchar(char c1, char c2, char *new, int index)
{
    char *hex1;
    char *hex2;

    hex2 = chartohex(c2, "0123456789abcdef");
    if (!hex2)
        return (-1);
    new[index++] = ' ';
    new[index++] = hex2[0];
    new[index++] = hex2[1];
    free(hex2);
    hex1 = chartohex(c1, "0123456789abcdef");
    if (!hex1)
        return (-1);
    new[index++] = hex1[0];
    new[index] = hex1[1];
    free(hex1);
    return (0);
}

char *hexcount(size_t count, const char *base)
{
    char *new;
    int size;

    size = 8;
    if ((new = malloc((size + 1) * sizeof(char))) == NULL)
        return (NULL);
    new[size--] = '\0';
    new[size] = '0';
    while ((size--) > 0)
    {
        new[size] = base[count % 16];
        count /= 16;
    }
    return (new);
}

char *strhexreprC(char *str, int size)
{
    char *new;
    int len;
    int index;

    if ((new = malloc((16 * 3 + 2) * sizeof(char))) == NULL)
        return (NULL);
    new[49] = '\0';
    len = 0;
    index = 0;
    while (len < size)
    {
        if (write_hexcharC(str[len], new, index))
            return (NULL);
        index += 3;
        len++;
        if (index == 24)
            new[index++] = ' ';
    }
    while (index < 49)
        new[index++] = ' ';
    return (new);
}

char *strhexrepr(char *str, int size)
{
    char *new;
    int len;
    int index;

    if ((new = malloc((8 * 5 + 1) * sizeof(char))) == NULL)
        return (NULL);
    new[40] = '\0';
    len = 0;
    index = 0;
    while (len < size)
    {
        if (write_hexchar(str[len], str[len + 1], new, index))
            return (NULL);
        index += 5;
        len += 2;
    }
    while (index < 40)
        new[index++] = ' ';
    return (new);
}