#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;
typedef node_t bst_t;
// Write your code here
// ...
node_t *createnode(int val){
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
bst_t* minValueNode(bst_t* root) {
    bst_t* curr = root;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}
int find_min(bst_t *root){
    bst_t *curr = root;
    while (curr && curr->left){
        curr = curr->left;
    }
    return curr->data;
}
int find_max(bst_t *root){
    bst_t *curr = root;
    while (curr && curr->right){
        curr = curr->right;
    }
    return curr->data;
}
bst_t *insert(bst_t *root,int val){
    node_t *temp = createnode(val);
    if (root == NULL){
        root = temp;
        return root;
    }
    if (val <= root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
bst_t* delete(bst_t* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data > root->data) {
        root->right = delete(root->right, data);
    } else if (data < root->data) {
        root->left = delete(root->left, data);
    } else {
        if (root->left == NULL) {
            bst_t* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t* temp = root->left;
            free(root);
            return temp;
        }
        bst_t* minNode = minValueNode(root->right);
        root->data = minNode->data;
        root->right = delete(root->right, minNode->data);
    }
    return root;
}
int find(node_t *root,int data){
    if (root == NULL){
        return 0;
    }
    if (data < root->data){
        return find(root->left,data);
    }
    else if (data > root->data){
        return find(root->right,data);
    }
    else
        return 1;
}
int main(void)
{
    bst_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &command);
        switch (command){
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}
