#include "./ft_btree.h"

t_btree *btree_create_node(void *item)
{
    t_btree *new;

    new = NULL;
    new = (t_btree *)malloc(sizeof(t_btree));
    if (new)
    {
        new->item = item;
        new->left = NULL;
        new->right = NULL;
    }
    return (new);
}