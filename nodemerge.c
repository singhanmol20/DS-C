#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node* next;
}*firstnode1, *firstnode2;
void merge(){
    struct node* tmp;
    tmp=firstnode1;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=firstnode2;
}
void output(){
    struct node *tmp;
    printf("the output is\n");
    tmp=firstnode1;
    while(tmp!=NULL){
        printf("%d\n",tmp->num);
        tmp=tmp->next;
    }
}

int main(){
    struct node* newnode, *tmp1;
    firstnode1= (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the first node of SLL 1 ");
    scanf("%d",&firstnode1->num);
    firstnode1->next=NULL;
    tmp1=firstnode1;
    for(int i=0;i<4;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->num);
        newnode->next=NULL;
        tmp1->next=newnode;
        tmp1=tmp1->next;
    }
     firstnode2= (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of the first node of SLL 2 ");
    scanf("%d",&firstnode2->num);
    firstnode2->next=NULL;
    tmp1=firstnode2;
    for(int i=0;i<4;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->num);
        newnode->next=NULL;
        tmp1->next=newnode;
        tmp1=tmp1->next;
    }
    merge();
    output();
}