#include "./ft_btree.h"

//this does not make use of the property of BSTs; aka less at the left, more at the right
void *btree_search_item(t_btree *root, void *item, int (*cmp)(void *, void *))
{
    void *found;

    found = NULL;
    if (root && cmp)
    {
        if (root->left)
            found = btree_search_item(root->left, item, cmp);
        if (!found && ((*cmp)(item, root->item) == 0))
            return (root->item);
        if (!found && (root->right))
            found = btree_search_item(root->right, item, cmp);
    }
    return (found);
}
