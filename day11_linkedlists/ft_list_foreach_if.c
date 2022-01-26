#include "./ft_list.h"

void ft_list_foreach_if(t_list *head, void (*func)(void *), void *data_ref, int (*cmp)())
{
    if (!func || !cmp)
        return;
    while (head)
    {
        if ((*cmp)(head->data, data_ref) == 0)
            (*func)(head->data);
        head = head->next;
    }
}