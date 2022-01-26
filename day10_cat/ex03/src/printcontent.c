#include "../includes/hexdump.h"

int writelastline(const char *base, int size, int c, int offset)
{
    char *count;

    if (size != 16)
        c--;
    count = hexcount(c, base);
    if (!count)
        return (1);
    count[7] = base[size % 16];
    write(STDOUT_FILENO, count + offset, ft_strlen(count + offset));
    write(STDOUT_FILENO, "\n", 1);
    free(count);
    return (0);
}

int print(char *buf, int count, const char *base)
{
    int i;
    int c;
    int size;

    i = 0;
    c = 0;
    while (i < count)
    {
        size = 16;
        if ((count - i) < 16)
            size = (count - i);
        if (writeline(buf + i, base, size, c))
            return (1);
        i += 16;
        c++;
    }
    return (writelastline(base, size, c, 1));
}

int printC(char *buf, int count, int op, const char *base)
{
    int i;
    int c;
    int j;
    int size;

    i = 0;
    c = 0;
    while (i < count)
    {
        size = 16;
        if ((count - i) < 16)
            size = (count - i);
        j = 0;
        while (j++ < op)
        {
            if (writelineC(buf + i, base, size, c))
                return (1);
        }
        c++;
        i += 16;
    }
    return (writelastline(base, size, c, 0));
}

int print_content(char *buf, int charcount, int op)
{
    int status;

    if (op == 0)
    {
        status = print(buf, charcount, "0123456789abcdef");
        free(buf);
        return (status);
    }
    status = printC(buf, charcount, op, "0123456789abcdef");
    free(buf);
    return (status);
}

int print_stdin(char *buf, int op)
{
    int charcount;
    int status;

    charcount = 0;
    if ((status = read_file(buf, NULL, &charcount)))
    {
        if (status != -2)
            free(buf);
        handle_file_errors(status, "stdin");
        return (1);
    }
    return (print_content(buf, charcount, op));
}
