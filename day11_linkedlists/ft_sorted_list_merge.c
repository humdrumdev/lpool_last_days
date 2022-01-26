#include "./ft_list.h"

t_list *ft_list_insert_one(t_list **head, t_list **prev, t_list **new, int (*cmp)())
{
    t_list *current;
    t_list *next;

    current = *head;
    while (current->next)
    {
        if ((*cmp)((*new)->data, current->data) <= 0)
        {
            next = (*new)->next;
            (*new)->next = current;
            if (!(*prev))
                *head = *new;
            else
                (*prev)->next = *new;
            *prev = *new;
            *new = next;
            return (next);
        }
        *prev = current;
        current = current->next;
    }
    current->next = *new;
    return (NULL);
}

void ft_sorted_list_merge(t_list **head, t_list *new, int (*cmp)())
{
    t_list *prev;

    if (!head || !new || !cmp)
        return;
    if (!(*head))
    {
        *head = new;
        return;
    }
    prev = NULL;
    while (new)
        new = ft_list_insert_one(head, &prev, &new, cmp);
}

// int cmp(char *lhs, char *rhs)
// {
//     return (lhs[0] - rhs[0]);
// }
// void func(void *data)
// {
//     char *str = (char *)data;
//     str[0] = str[0] - 32;
// }

// int main(int ac, char **av)
// {
//     char *s[] = {"A", "B", "C", "D", NULL};

//     t_list *lst = ft_list_push_params(ac, av);
//     t_list *lst2 = ft_list_push_params(4, s);
//     t_list *head = lst;

//     ft_list_sort(&lst, cmp);
//     ft_list_sort(&lst2, cmp);
//     while (lst)
//     {
//         printf("%s\n", (char *)(lst->data));
//         lst = lst->next;
//     }
//     printf("----------\n");
//     ft_sorted_list_merge(&head, lst2, cmp);
//     while (head)
//     {
//         printf("%s\n", (char *)(head->data));
//         head = head->next;
//     }
//     return (0);
// }