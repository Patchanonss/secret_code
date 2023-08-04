#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;
int isNumberInNumber(int numberToCheck, int number) {
    char numberStr[20];
    char numberToCheckStr[3];
    sprintf(numberStr, "%d", number);
    sprintf(numberToCheckStr, "%d", numberToCheck);
    if (strstr(numberStr, numberToCheckStr) != NULL) {
        return 1;
    }
    return 0;
}
node_t *append(node_t *,int);
void delete(node_t*,int);
void show(node_t*);
int get(node_t*,int);
node_t *access1(node_t *head,int index);
int main(){
    node_t *head = NULL;
    node_t *label = NULL;
    int player,magicnum,ind;
    scanf("%d %d",&player,&magicnum);
    for (int u = 1;u<player+1;u++){
        int temp1;
        scanf("%d",&temp1);
        head = append(head,temp1);
        label = append(label,u);
    }
    ind = 0;
    int count = 1;
    while (head->next != NULL){
        if (ind > player - 1){
            ind = 0;
        }
        if (count%magicnum == 0 || isNumberInNumber(magicnum,count)){
            access1(head,ind)->data -= 1;
            if (access1(head,ind)->data < 0){
                if(ind == 0){
                    head = head->next;
                    label = label->next;
                }
                else{
                    delete(head,ind);
                    delete(label,ind);
                }
                player--;
                count++;
                continue;
            }
        }
        count++;
        ind++;
    }
    show(label);
}
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
node_t *append(node_t *head,int data){
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    int dataTemp = data;
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
int get(node_t *head,int index){
    node_t *curr = head;
    for (int i = 0;i<index;i++){
        curr = curr->next;
    }
    return curr->data;
}
node_t *access1(node_t *head,int index){
    node_t *curr = head;
    for (int i = 0;i<index;i++){
        curr = curr->next;
    }
    return curr;
}
void delete(node_t *head,int index){
    node_t *temp2;
    node_t *temp1 = head;
    for (int i = 0;i<index-1;i++){
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}