#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;
node_t *append(node_t *);
void get(node_t *);
void show(node_t* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    while(head->next != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}
node_t *reverse(node_t *);
node_t *cut(node_t*);
int main() {
    node_t *startNode;
    int n,i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                startNode = append(startNode);
                break;
            case 'G':
                get(startNode);
                break;
            case 'S':
                show(startNode);
                break;
            case 'R':
                startNode = reverse(startNode);
                break;
            case 'C':
                startNode = cut(startNode);
                break;
            default:
                break;
        }
    }
    return 0;
}
node_t *append(node_t *head){
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    int dataTemp;
    scanf(" %d",&dataTemp);
    temp->data = dataTemp;
    temp->next = NULL;
    if (head == NULL){
        return temp;
    }
    node_t *curr;
    curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void get(node_t *head){
    node_t *curr = head;
    int index;
    scanf(" %d",&index);
    for (int i = 0;i<index;i++){
        curr = curr->next;
    }
    printf("%d\n",curr->data);
}
node_t *reverse(node_t *head){
    node_t *curr = head;
    node_t *prev = NULL;
    node_t *after;
    while(curr != NULL){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    head = prev;
    return head;
}
node_t *cut(node_t *head){
    node_t *first,*last;
    first = last = head;
    int a,b;
    scanf(" %d %d",&a,&b);
    for (int i = 0;i<a;i++){
        first = first->next;
    }
    head = first;
    for (int j = 0;j<b;j++){
        last = last->next;
    }
    last->next = NULL;
    return head;
}