#include <stdio.h>
#include <stdlib.h>
#include "week8.h"
#ifndef __bin_tree__
typedef struct node {
int data;
struct node *left;
struct node *right;
} node_t;
typedef node_t tree_t;
#endif
typedef struct list1{
    int val;
    struct list1 *next;
}list1;
list1 *createlist(int sval){
    list1 *temp = (list1*)malloc(sizeof(list1));
    temp->val = sval;
    temp->next = NULL;
    return temp;
}
list1 *push(list1 *head,int val1){
    list1* temp = createlist(val1);
    if (head == NULL){
        head = temp;
        return head;
    }
    list1 *curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void show(list1* head){
    while (head != NULL){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}
list1 *headpre = NULL;
list1 *headin = NULL;
list1 *headpost = NULL;
void fake_preorder(tree_t *root){
    if (root == NULL){
        return;
    }
    headpre = push(headpre,root->data);
    // printf("%d ",root->data);
    fake_preorder(root->left);
    fake_preorder(root->right);
}
void fake_postorder(tree_t *root){
    if (root == NULL){
        return;
    }
    fake_postorder(root->left);
    fake_postorder(root->right);
    headpost = push(headpost,root->data);
}
void fake_inorder(tree_t *root){
    if (root == NULL){
        return;
    }
    fake_inorder(root->left);
    headin = push(headin,root->data);
    fake_inorder(root->right);
}
void print_preorder(tree_t *root){
    fake_preorder(root);
    show(headpre);
}
void print_inorder(tree_t *root){
    fake_inorder(root);
    show(headin);
}
void print_postorder(tree_t *root){
    fake_postorder(root);
    show(headpost);
}
int main(void){
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d %d", &parent, &child,&branch);
        t = attach(t, parent, child, branch);
    }
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0;
}