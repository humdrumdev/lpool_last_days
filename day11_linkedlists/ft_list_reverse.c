#include "./ft_list.h"

void ft_list_reverse(t_list **head)
{
    t_list *previous;
    t_list *current;
    t_list *next;

    if (!head)
        return;
    previous = NULL;
    next = NULL;
    current = *head;
    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}