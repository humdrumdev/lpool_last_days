#include "./ft_btree.h"

t_queue *ft_create_queue()
{
    t_queue *q;

    q = (t_queue *)malloc(sizeof(t_queue));
    if (!q)
        return (NULL);
    q->head = NULL;
    q->tail = NULL;
    return (q);
}

int ft_enqueue(t_queue *q, t_btree *new, int level)
{
    t_node *node;

    if (!q || !new)
        return (1);
    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (1);
    node->content = (t_btree *)malloc(sizeof(t_btree));
    node->content = new;
    node->level = level;
    node->next = NULL;
    if (q->tail)
        q->tail->next = node;
    q->tail = node;
    if (!(q->head))
        q->head = node;
    return (0);
}

t_node *ft_dequeue(t_queue *q)
{
    t_node *head;
    t_node *ret;

    if (!q || !(q->head))
        return (NULL);
    head = q->head;
    ret = head;
    q->head = q->head->next;
    if (!(q->head))
        q->tail = NULL;
    return (ret);
}