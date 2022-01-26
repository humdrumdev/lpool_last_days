#include "./ft_list.h"

void ft_swap(t_list *lhs, t_list *rhs)
{
    void *temp;

    temp = lhs->data;
    lhs->data = rhs->data;
    rhs->data = temp;
}

void ft_list_sort(t_list **head, int (*cmp)())
{
    t_list *last;
    t_list *current;
    int sorted;

    if (!head || !(*head) || !cmp)
        return;
    last = NULL;
    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        current = *head;
        while (current->next != last)
        {
            if ((*cmp)(current->data, current->next->data) > 0)
            {
                ft_swap(current, current->next);
                sorted = 0;
            }
            current = current->next;
        }
        last = current;
    }
}