#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *next;
} node_t;
typedef node_t stack;
void show(node_t*);
char top(stack *hs){
    if (hs == NULL){
        // printf("Stack is empty.\n");
        return '\0';
    }
    return hs->data;
}
stack* pop(stack *hs){
    stack *temp = hs;
    if (hs == NULL){
        return hs;
    }
    hs = hs->next;
    free(temp);
    return hs;
}
stack* push(stack *hs,char x){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp->data = x;
    temp->next = hs;
    return temp;
}
int main(void) {
    int n;
    scanf("%d\n",&n);
    if (n%2 != 0){
        printf("%d\n",0);
        return 0;
    }
    stack *head = NULL;
    char *str1 = (char *)malloc(n * sizeof(char));
    for (int i = 0;i<n;i++){
        char m;
        scanf("%c",&m);
        if (top(head) == '(' && m == ')'){
            head = pop(head);
        }
        else if (top(head) == '[' && m == ']'){
            head =  pop(head);
        }
        else if (top(head) == '{' && m == '}'){
            head =  pop(head);
        }
        else{
            head = push(head,m);
        }
    }
    if(head != NULL){
        printf("0\n");
    }
    else{
        printf("1\n");
    }
    
}
void show(stack* head){
    if (head == NULL){
        printf("\n");
        return;
    }
    while(head != NULL){
        printf("%c ",head->data);
        head = head->next;
    }
    printf("\n");
}