#ifndef FT_BTREE_H
#define FT_BTREE_H

#include <stdio.h>
#include <stdlib.h>

#define INT_MIN (1 << 31)

typedef struct s_btree
{
    struct s_btree *left;
    struct s_btree *right;
    void *item;
} t_btree;

typedef struct s_node
{
    t_btree *content;
    int level;
    struct s_node *next;
} t_node;

typedef struct
{
    t_node *head;
    t_node *tail;
} t_queue;

t_btree *btree_create_node(void *item);
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void btree_insert_data(t_btree **root, void *data, int (*f)(void *, void *));
void *btree_search_item(t_btree *root, void *item, int (*cmp)(void *, void *));
void btree_apply_by_level(t_btree *root, void (*func)(void *, int, int));
int btree_level_count(t_btree *root);
int btree_node_depth(t_btree *root, t_btree *curr);

/*queue funcs*/
t_queue *ft_create_queue();
int ft_enqueue(t_queue *q, t_btree *new, int level);
t_node *ft_dequeue(t_queue *q);

#endif