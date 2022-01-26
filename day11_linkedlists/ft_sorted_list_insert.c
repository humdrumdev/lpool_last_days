#include "./ft_list.h"

int ft_move_to_next(t_list **current, t_list **prev, t_list *new)
{
    *prev = *current;
    if ((*current)->next)
    {
        *current = (*current)->next;
        return (0);
    }
    (*current)->next = new;
    return (1);
}

int ft_insert(t_list **head, t_list *new, int (*cmp)())
{
    t_list *prev;
    t_list *current;

    prev = NULL;
    current = *head;
    while (current)
    {
        if ((*cmp)(new->data, current->data) <= 0)
        {
            new->next = current;
            if (!prev)
                *head = new;
            else
                prev->next = new;
            return (0);
        }
        if (ft_move_to_next(&current, &prev, new))
            return (0);
    }
    return (1);
}

void ft_sorted_list_insert(t_list **head, void *data, int (*cmp)())
{
    t_list *new;

    new = ft_create_elem(data);
    if (!new || !head || !cmp)
        return;
    if (ft_insert(head, new, cmp))
        *head = new;
}