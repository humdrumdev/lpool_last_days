#include "../includes/hexdump.h"

int valid_arg(char *candidate, const char *arg)
{
    size_t len;

    len = ft_strlen(arg);
    if (ft_strlen(candidate) == len)
    {
        if (ft_strncmp(candidate, arg, len) == 0)
            return (0);
        return (-1);
    }
    if (ft_strncmp(candidate, arg, len) == 0)
        return (-2);
    return (-1);
}

t_result check_input(int ac, char **av)
{
    t_result res;
    int i;

    i = 0;
    res.numfiles = 0;
    res.numflags = 0;
    res.code = 0;
    while (++i < ac)
    {
        if (av[i][0] == '-')
        {
            if ((res.code = valid_arg(av[i], "-C")) == 0)
                res.flags[res.numflags++] = i;
            else
            {
                res.flags[res.numflags++] = i;
                return (res);
            }
        }
        else
            res.files[res.numfiles++] = i;
    }
    res.files[res.numfiles] = 0;
    res.flags[res.numflags] = 0;
    return (res);
}

int handle_input_errors(int code, char *arg)
{
    char op[2];

    op[1] = '\0';
    op[0] = arg[1];
    if (code == -2)
        op[0] = arg[2];
    logerr(INVALID_OP, INVALID_OP_P, op);
    return (1);
}

int main(int ac, char **av)
{
    t_result result;
    char *buf;
    int charcount;
    int status;

    if ((buf = malloc(MAX_BUF_SIZE)) == NULL)
        exit(EXIT_FAILURE);
    charcount = 0;
    result = check_input(ac, av);
    if (result.code < 0)
        exit(handle_input_errors(result.code, av[result.flags[result.numflags - 1]]));
    if ((result.numfiles == 0))
        exit(print_stdin(buf, result.numflags));
    if ((status = readfiles(buf, &charcount, av, result.files)) == -1)
        exit(EXIT_FAILURE);
    if (charcount == 0)
    {
        free(buf);
        exit(status);
    }
    exit(print_content(buf, charcount, result.numflags) || status);
}