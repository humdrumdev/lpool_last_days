#include "./ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new;
    t_list *next;

    new = ft_create_elem(data);
    if (new && (begin_list))
    {
        if (*begin_list)
        {
            next = (*begin_list);
            while (next->next)
                next = next->next;
            next->next = new;
        }
        else
            *begin_list = new;
    }
}