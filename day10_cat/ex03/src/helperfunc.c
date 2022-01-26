#include "../includes/hexdump.h"

int ft_isprint(char c)
{
    return ((c >= 32) && (c != 127));
}

char *chartohex(int c, const char *base)
{
    unsigned char uc;
    char *new;
    int len;
    if ((new = malloc(3 * sizeof(char))) == NULL)
        return (NULL);
    len = 2;
    new[len--] = '\0';
    if ((c >= 0) && (c < 16))
    {
        new[len--] = base[c];
        new[len] = '0';
        return (new);
    }
    uc = c;
    while (uc > 0)
    {
        new[len--] = base[uc % 16];
        uc /= 16;
    }
    return (new);
}

char *strrepr(char *str, int size)
{
    char *new;
    int len;

    if ((new = malloc((size + 3) * sizeof(char))) == NULL)
        return (NULL);
    len = size - 1;
    size += 2;
    new[0] = '|';
    new[size--] = '\0';
    new[size] = '|';
    while (size-- > 1)
    {
        if (ft_isprint(str[len]))
            new[size] = str[len];
        else
            new[size] = '.';
        len--;
    }
    return (new);
}

int writeline(char *buf, const char *base, int size, int c)
{
    char *line;

    line = hexcount(c, base);
    if (!line)
        return (1);
    write(STDOUT_FILENO, line + 1, ft_strlen(line + 1));
    free(line);
    line = strhexrepr(buf, size);
    if (!line)
        return (1);
    write(STDOUT_FILENO, line, ft_strlen(line));
    write(STDOUT_FILENO, "\n", 1);
    free(line);
    return (0);
}

int writelineC(char *buf, const char *base, int size, int c)
{
    char *line;

    line = hexcount(c, base);
    if (!line)
        return (1);
    write(STDOUT_FILENO, line, ft_strlen(line));
    write(STDOUT_FILENO, "  ", 2);
    free(line);
    line = strhexreprC(buf, size);
    if (!line)
        return (1);
    write(STDOUT_FILENO, line, ft_strlen(line));
    write(STDOUT_FILENO, " ", 1);
    line = strrepr(buf, size);
    if (!line)
        return (1);
    write(STDOUT_FILENO, line, ft_strlen(line));
    write(STDOUT_FILENO, "\n", 1);
    free(line);
    return (0);
}