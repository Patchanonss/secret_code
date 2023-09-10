#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "week8.h"
#ifndef __bin_tree__
#define __bin_tree__
typedef struct node{
    int data;
    int nb;
    struct node *left;
    struct node *right;
} tree_t;
#endif
int countnode(tree_t *root){
    if (root == NULL){
        return 0;
    }
    return 1 + countnode(root->left) + countnode(root->right);
}
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
int maxDepth(tree_t * root) {

    if (root == NULL) {
        return 0;
    }
    return max(
        maxDepth(root->left),
        maxDepth(root->right)
    ) + 1;
}
int is_full(tree_t *root){
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    else if (root->left != NULL && root->right == NULL){
        return 0;
    }
    else if (root->left == NULL && root->right != NULL)
        return 0;
    else if (root->left != NULL && root->right != NULL){
        return is_full(root->left) && is_full(root->right);
    }
}
int is_perfect(tree_t *root){
    int h = maxDepth(root) - 1;
    int n = countnode(root);
    if (n != pow(2,h+1)-1){
        return 0;
    }
    return 1;
}
int complete(tree_t *t, int idx, int node){
    if (t == NULL)
        return 1;
    if (idx >= node)
        return 0;
    if (complete(t->left, 2*idx+1, node) && complete(t->right, 2*idx+2, node))
        return 1;
    return 0;
}
int is_complete(tree_t *root){
    int nodenum = countnode(root);
    return complete(root, 0, nodenum);
}
int fake_degenerate(tree_t *root,int currh){
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    if (root->left != NULL && root->right != NULL){
        if (currh != 1){
            return 1;
        }
        return 0;
    }
    int a,b;
    a = 0;
    b = 0;
    if (root->left != NULL){
        a = fake_degenerate(root->left,currh+1);
    }
    if (root->right != NULL){
        b = fake_degenerate(root->right,currh+1);
    }
    if (a ^ b){
        return 1;
    }
    return 0;
}
int is_degenerate(tree_t *root){
    return fake_degenerate(root,1);
}
int only_left(tree_t *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 1;
    }
    if (root->right != NULL) {
        return 0;
    }
    return only_left(root->left) && only_left(root->right);
}
int only_right(tree_t* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 1; 
    }
    
    if (root->left != NULL) {
        return 0;
    }
    return only_right(root->left) && only_right(root->right);
}
int is_skewed(tree_t *root){
    return only_left(root) ^ only_right(root);
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,
        &branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t),
    is_perfect(t), is_complete(t),
    is_degenerate(t), is_skewed(t));
    return 0;
}
