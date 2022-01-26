#include "./ft_list.h"

void ft_remove(t_list **head, t_list **previous, t_list **current)
{
    t_list *next;

    next = (*current)->next;
    free(*current);
    *current = next;
    if (*previous)
        (*previous)->next = *current;
    else
        *head = *current;
}

void ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)())
{
    t_list *previous;
    t_list *current;

    if (!cmp || !head)
        return;
    previous = NULL;
    current = *head;
    while (current)
    {
        if ((*cmp)(current->data, data_ref) == 0)
            ft_remove(head, &previous, &current);
        else
        {
            previous = current;
            current = current->next;
        }
    }
}