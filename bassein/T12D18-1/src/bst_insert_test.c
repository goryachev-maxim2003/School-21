#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree* tree1 = bstree_create_node(8);
    bstree_insert(tree1, 3, comparator);
    bstree_insert(tree1, 10, comparator);
    bstree_insert(tree1, 1, comparator);
    bstree_insert(tree1, 6, comparator);
    bstree_insert(tree1, 14, comparator);
    bstree_insert(tree1, 13, comparator);
    bstree_insert(tree1, 4, comparator);
    bstree_insert(tree1, 7, comparator);
    bstree_insert(tree1, 5, comparator);
    bstree_apply_infix(tree1, applyf);
    destroy(tree1);
    free(tree1);
    return 0;
}
// new