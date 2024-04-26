#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree *tree1 = bstree_create_node(4);
    t_btree *tree2 = bstree_create_node(5);

    printf("tree1 test:  elem=%d left=%s right=%s\n", tree1->elem, (char *)tree1->left, (char *)tree1->right);
    printf("tree2 test:  elem=%d left=%s right=%s", tree2->elem, (char *)tree2->left, (char *)tree2->right);

    free(tree1);
    free(tree2);

    return 0;
}
