#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

t_list *ft_create_elem(void *data);
void ft_list_push_back(t_list **begin_list, void *data);
void ft_list_push_front(t_list **begin_list, void *data);
t_list *ft_list_push_params(int ac, char **av);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
void ft_list_clear(t_list **begin_list);
t_list *ft_list_at(t_list *begin_list, unsigned int n);
void ft_list_reverse(t_list **head);
void ft_list_foreach(t_list *head, void (*func)(void *));
void ft_list_foreach_if(t_list *head, void (*func)(void *), void *data_ref, int (*cmp)());
t_list *ft_list_find(t_list *begin, void *data_ref, int (*cmp)());
void ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)());
void ft_list_merge(t_list **head, t_list *new);
void ft_list_sort(t_list **head, int (*cmp)());
void ft_list_reverse_fun(t_list *head);
void ft_sorted_list_insert(t_list **head, void *data, int (*cmp)());
void ft_sorted_list_merge(t_list **head, t_list *new, int (*cmp)());

#endif