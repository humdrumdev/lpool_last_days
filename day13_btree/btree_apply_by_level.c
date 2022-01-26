#include "./ft_btree.h"

int btree_node_depth(t_btree *root, t_btree *curr)
{
    int a;
    int b;

    a = INT_MIN;
    b = INT_MIN;
    if (!root || !curr)
        return INT_MIN;
    if (root == curr)
        return (0);
    if ((root->left == curr) || (root->right == curr))
        return (1);
    if (root->left)
        a = btree_node_depth(root->left, curr);
    if ((a < 0) && root->right)
        b = btree_node_depth(root->right, curr);
    if (a > b)
        return (a + 1);
    return (b + 1);
}

void btree_apply_by_level(t_btree *root, void (*func)(void *, int, int))
{
    t_queue *q;
    t_node *node;
    int level;

    if (!root)
        return;
    ft_enqueue(q = ft_create_queue(), root, 0);
    level = 1;
    while (q->tail)
    {
        node = ft_dequeue(q);
        (*func)(node->content->item, node->level, (level != node->level));
        level = btree_node_depth(root, node->content->left);
        if (node->content->left)
            ft_enqueue(q, node->content->left, level);
        level = btree_node_depth(root, node->content->right);
        if (node->content->right)
            ft_enqueue(q, node->content->right, level);
        level = node->level;
    }
    free(node);
    free(q);
}

void func(void *data, int a, int b)
{
    printf("%s : l == %d  f == %d\n", (char *)data, a, b);
}

int cmp(void *l, void *r)
{
    char *a = (char *)l;
    char *b = (char *)r;
    return (a[0] - b[0]);
}

int main()
{
    t_btree *root;

    root = NULL;
    btree_insert_data(&root, "f1", cmp);
    btree_insert_data(&root, "d1", cmp);
    btree_insert_data(&root, "j1", cmp);
    btree_insert_data(&root, "b1", cmp);
    btree_insert_data(&root, "a1", cmp);
    btree_insert_data(&root, "c1", cmp);
    btree_insert_data(&root, "g1", cmp);
    btree_insert_data(&root, "k1", cmp);
    btree_insert_data(&root, "e1", cmp);
    btree_insert_data(&root, "i1", cmp);
    btree_insert_data(&root, "h1", cmp);
    btree_insert_data(&root, "h1", cmp);
    btree_apply_by_level(root, func);

    return (0);
}