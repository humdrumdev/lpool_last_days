#include "./ft_btree.h"

int ft_max(int a, int b)
{
    if (a < b)
        return (b);
    return (a);
}

//this calculates the number of nodes in the largest branch..root included
int btree_level_count(t_btree *root)
{
    if (!root)
        return (0);
    if (!(root->left) && !(root->right))
        return (1);
    if (!(root->right))
        return (1 + btree_level_count(root->left));
    if (!(root->left))
        return (1 + btree_level_count(root->right));
    return (1 + ft_max(btree_level_count(root->left), btree_level_count(root->right)));
}