#include "../includes/hexdump.h"

extern int errno;

int read_content(int fd, char *buf, int charcount)
{
    int status;
    while ((charcount < MAX_BUF_SIZE) && (status = read(fd, buf + charcount, 1)) > 0)
        charcount++;
    if (status == -1)
        return (-errno);
    if (charcount >= MAX_BUF_SIZE)
        return (MAX_BUF_SIZE);
    return (charcount);
}

int read_file(char *buf, char *fname, int *charcount)
{
    int fd;
    int prev;
    int status;

    fd = 0;
    if (fname && ((fd = open(fname, O_RDONLY)) < 0))
        return (errno);
    prev = *charcount;
    *charcount = read_content(fd, buf, *charcount);
    if (*charcount == MAX_BUF_SIZE)
    {
        free(buf);
        return (-2);
    }
    if (*charcount < 0)
    {
        status = -(*charcount);
        *charcount = prev;
        return (status);
    }
    close(fd);
    return (0);
}

/*
** readfiles returns 1 if any file is erroneous, this is used to return an exit satus
** note that hexdump returns 0, but it's good practice to return a non null status code
** in this case
*/

int readfiles(char *buf, int *charcount, char **av, int *indices)
{
    int i;
    int status;
    int code;

    i = 0;
    code = 0;
    while (indices[i] != 0)
    {
        if ((status = read_file(buf, av[indices[i]], charcount)) != 0)
        {
            code = 1;
            handle_file_errors(status, av[indices[i]]);
            if (status == -2)
                return (-1);
        }
        i++;
    }
    return (code);
}