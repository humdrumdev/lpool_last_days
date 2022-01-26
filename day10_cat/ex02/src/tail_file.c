#include "../includes/tail.h"

extern int errno;

int getmin(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int open_file(char *f)
{
    int fd;

    fd = 0;
    if (f)
        fd = open(f, O_RDONLY);
    return (fd);
}

void write_content(int bytes, int lines, int charcount, char *buf)
{
    if (bytes > 0)
    {
        bytes = getmin(bytes, charcount);
        write(STDOUT_FILENO, buf + charcount - bytes, bytes);
        return;
    }
    lines = getmin(lines, NUM_LINES);
    if (lines < NUM_LINES)
    {
        write(STDOUT_FILENO, buf, charcount);
        return;
    }
    bytes = charcount;
    while (--charcount && (lines-- > -1))
    {
        while (buf[charcount] != '\n')
            charcount--;
    }
    write(STDOUT_FILENO, buf + charcount + 2, bytes - charcount - 2);
}

int read_content(int fd, char *buf, int *lines)
{
    int charcount;
    int status;

    charcount = 0;
    while ((status = read(fd, buf + charcount, 1)) > 0)
    {
        if (buf[charcount] == '\n')
            (*lines)++;
        charcount++;
        if (charcount == MAX_BUF_SIZE)
        {
            close(fd);
            return (MAX_BUF_SIZE);
        }
    }
    if (status == -1)
        return (-errno);
    return (charcount);
}

int tail_file(char *fname, int bytes, int ac)
{
    int fd;
    int lines;
    int charcount;
    char *buf;

    if (((fd = open_file(fname)) < 0) || ((buf = malloc(MAX_BUF_SIZE)) == NULL))
        return (errno);
    lines = 0;
    charcount = read_content(fd, buf, &lines);
    if (charcount == MAX_BUF_SIZE)
    {
        free(buf);
        return (-2);
    }
    if (charcount < 0)
        return (-charcount);
    if (fname && (ac > 2))
        logstrs(HEAD_P, HEAD_S, fname);
    write_content(bytes, lines, charcount, buf);
    free(buf);
    close(fd);
    return (0);
}