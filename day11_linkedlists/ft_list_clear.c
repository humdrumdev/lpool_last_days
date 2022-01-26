#include "./ft_list.h"

void ft_list_clear(t_list **begin_list)
{
    t_list *current;
    t_list *temp;

    if (begin_list && *begin_list)
    {
        current = *begin_list;
        while (current->next)
        {
            temp = current->next;
            free(current);
            current = temp;
        }
        free(current);
        *begin_list = NULL;
    }
}