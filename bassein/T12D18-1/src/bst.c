#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

// void output(t_btree *root) {
//     if (root != NULL) {
//         printf("elem:%d ", root->elem);
//         if (root->left != NULL) printf("left:%d ", root->left->elem);
//         if (root->right != NULL) printf("right:%d", root->right->elem);
//         printf("\n");
//         output(root->right);
//         output(root->left);
//     }
// }
void applyf(int elem) { printf("%d ", elem); }

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        if (root->left != NULL)
            applyf(root->left->elem);
        else
            printf("null ");
        applyf(root->elem);
        if (root->right != NULL)
            applyf(root->right->elem);
        else
            printf("null ");
        printf("\n");
        bstree_apply_infix(root->right, applyf);
        bstree_apply_infix(root->left, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->elem);
        if (root->left != NULL)
            applyf(root->left->elem);
        else
            printf("null ");
        if (root->right != NULL)
            applyf(root->right->elem);
        else
            printf("null ");
        printf("\n");
        bstree_apply_prefix(root->right, applyf);
        bstree_apply_prefix(root->left, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        if (root->left != NULL)
            applyf(root->left->elem);
        else
            printf("null ");
        if (root->right != NULL)
            applyf(root->right->elem);
        else
            printf("null ");
        applyf(root->elem);
        printf("\n");
        bstree_apply_postfix(root->right, applyf);
        bstree_apply_postfix(root->left, applyf);
    }
}

t_btree *bstree_create_node(int item) {
    t_btree *new = malloc(sizeof(t_btree));
    new->elem = item;
    new->right = new->left = NULL;
    return new;
}

int comparator(const int p1, const int p2) {
    int ret = 0;
    if (p1 > p2)
        ret = 1;
    else if (p1 < p2)
        ret = -1;
    return ret;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    int cmp = cmpf(item, root->elem);
    if (cmp == 1) {
        if (root->right == NULL)
            root->right = bstree_create_node(item);
        else
            bstree_insert(root->right, item, cmpf);
    } else if (cmp == -1) {
        if (root->left == NULL)
            root->left = bstree_create_node(item);
        else
            bstree_insert(root->left, item, cmpf);
    } else
        printf("this element has already been added to the tree!");
}

void destroy(t_btree *root) {
    if (root != NULL) {
        t_btree *left = root->left;
        t_btree *right = root->right;
        destroy(left);
        destroy(right);
        if (left != NULL) free(left);
        if (right != NULL) free(right);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int));

void bstree_apply_prefix(t_btree *root, void (*applyf)(int));

void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
