#include "./ft_list.h"

t_list *ft_list_find(t_list *head, void *data_ref, int (*cmp)())
{
    if (!cmp)
        return (NULL);
    while (head)
    {
        if ((*cmp)(head->data, data_ref) == 0)
            return (head);
        head = head->next;
    }
    return (NULL);
}