#include "./ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int n)
{
    t_list *nth;
    unsigned int i;

    nth = NULL;
    i = 0;
    while (begin_list && (i < n))
    {
        begin_list = begin_list->next;
        i++;
    }
    if (i == n)
        nth = begin_list;
    return (nth);
}
