#include "./ft_list.h"

t_list *ft_list_last(t_list *begin_list)
{
    t_list *last;

    last = NULL;
    if (begin_list)
    {
        last = begin_list;
        while (last->next)
            last = last->next;
    }
    return (last);
}