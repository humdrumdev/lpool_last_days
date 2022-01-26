#include "./ft_list.h"

void ft_swap(t_list *lhs, t_list *rhs)
{
    void *temp;

    temp = lhs->data;
    lhs->data = rhs->data;
    rhs->data = temp;
}

void ft_list_reverse_fun(t_list *head)
{
    t_list *current;
    t_list *next;
    t_list *last;

    if (!head || !(head->next))
        return;
    current = head;
    while (current->next)
        current = current->next;
    last = current;
    current = head;
    while (current != last)
    {
        ft_swap(current, last);
        if (current->next == last)
            return;
        next = current->next;
        while (current->next != last)
            current = current->next;
        last = current;
        current = next;
    }
}