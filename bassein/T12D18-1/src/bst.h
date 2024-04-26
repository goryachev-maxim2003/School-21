#ifndef BTS_H
#define BTS_H

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int elem;
} t_btree;

// void output(t_btree *root);

void applyf(int elem);

void bstree_apply_infix(t_btree *root, void (*applyf)(int));

void bstree_apply_prefix(t_btree *root, void (*applyf)(int));

void bstree_apply_postfix(t_btree *root, void (*applyf)(int));

t_btree *bstree_create_node(int item);

int comparator(const int p1, const int p2);

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));

void destroy(t_btree *root);

void bstree_apply_infix(t_btree *root, void (*applyf)(int));

void bstree_apply_prefix(t_btree *root, void (*applyf)(int));

void bstree_apply_postfix(t_btree *root, void (*applyf)(int));

#endif
// new