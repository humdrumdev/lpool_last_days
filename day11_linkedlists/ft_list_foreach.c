#include "./ft_list.h"

void ft_list_foreach(t_list *head, void (*func)(void *))
{
    if (!func)
        return;
    while (head)
    {
        (*func)(head->data);
        head = head->next;
    }
}
