#include "./ft_list.h"

void ft_list_merge(t_list **head, t_list *new)
{
    t_list *last;

    if (!head || !new)
        return;
    last = *head;
    if (!last)
        *head = new;
    else
    {
        while (last->next)
            last = last->next;
        last->next = new;
    }
}