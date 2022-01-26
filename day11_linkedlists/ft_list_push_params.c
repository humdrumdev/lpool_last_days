#include "./ft_list.h"

t_list *ft_list_push_params(int ac, char **av)
{
    t_list *head;
    t_list *next;

    head = NULL;
    if (ac > 1)
    {
        head = ft_create_elem(av[ac - 1]);
        if (!head)
            return (NULL);
        ac--;
        next = head;
    }
    while (ac > 1)
    {
        next->next = ft_create_elem(av[--ac]);
        if (!(next->next))
            return (NULL);
        next = next->next;
    }
    return (head);
}