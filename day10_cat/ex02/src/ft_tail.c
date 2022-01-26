#include "../includes/tail.h"

int contains_elem(int *arr, int num, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[i] == num)
            return (1);
        i++;
    }
    return (0);
}

void on_failure(char *fname, int status, int count, int bytes)
{
    if ((status == EISDIR) && count > 1)
    {
        logerr(HEAD_P, HEAD_S, fname);
        if (bytes > 0)
        {
            handle_file_errors(status, fname);
            exit(EXIT_FAILURE);
        }
    }
    handle_file_errors(status, fname);
}

void tail_files(int ac, char **av, t_result result)
{
    int i;
    int count;
    int status;

    i = 1;
    count = ac - result.status.index;
    while (i < ac)
    {
        if (!contains_elem(result.idxtodrop, i, result.status.index))
        {
            status = tail_file(av[i], result.status.bytes, ac - result.status.index);
            if (status)
                on_failure(av[i], status, count, result.status.bytes);
            else if (count > 2)
                write(STDOUT_FILENO, "\n", 1);
            count--;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    t_result result;

    result = validate_input(ac, av, "-c");
    if (result.status.bytes == 0)
        exit(EXIT_SUCCESS);
    if (result.status.code < 0)
        exit(EXIT_FAILURE);
    if ((result.status.code == 1))
        return (tail_file(NULL, result.status.bytes, result.status.index));
    tail_files(ac, av, result);
    exit(EXIT_SUCCESS);
}