#include "./ft_btree.h"

void btree_insert_data(t_btree **root, void *data, int (*cmpf)(void *, void *))
{
    if (!root || !cmpf)
        return;
    if (!(*root))
        *root = btree_create_node(data);
    else
    {
        if ((*cmpf)(data, (*root)->item) < 0)
        {
            if ((*root)->left == NULL)
                (*root)->left = btree_create_node(data);
            else
                btree_insert_data(&((*root)->left), data, cmpf);
        }
        else
        {
            if ((*root)->right == NULL)
                (*root)->right = btree_create_node(data);
            else
                btree_insert_data(&((*root)->right), data, cmpf);
        }
    }
}

// void btree_insert_data(t_btree **root, void *data, int (*cmpf)(void *, void *))
// {
//     if (!root || !cmpf)
//         return;
//     if (!(*root))
//         *root = btree_create_node(data);
//     else
//     {
//         if ((*cmpf)(data, (*root)->item) < 0)
//             btree_insert_data(&((*root)->left), data, cmpf);
//         else
//             btree_insert_data(&((*root)->right), data, cmpf);
//     }
// }