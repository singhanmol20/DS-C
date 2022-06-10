 #include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
struct sk 
{
     int data;
     struct sk *next;
};
struct sk *top=NULL;
struct sk *push(struct sk *,int);
struct sk *display(struct sk *);
struct sk *pop(struct sk *);
int main(int argc,char *argv[])
{
    int val,choice;
    do
    {
        printf("\n * MAIN MENU **");
        printf(" \n 1.PUSH");
        printf(" \n 2.POP");
        printf(" \n 3.DISPLAY");
        printf(" \n 4.EXIT");
        printf(" \n Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\n Enter the number to be pushed on stack \n");
            scanf("%d",&val);
            top=push(top,val);
            break;
            case 2:
            top=pop(top);
            break;
            case 3:
            top=display(top);
            break;
            case 4:
            printf("Exit point \n");
            break;
        }
    }while(choice!=4);
    return 0;
}
struct sk *push(struct sk *top,int val)
{
    struct sk *ptr;
    ptr=malloc(sizeof(struct sk));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}


struct sk *display(struct sk *top)
{
    struct sk *ptr;
    ptr=top;
    if(top==NULL)
    printf(" \n STACK IS EMPTY \n");
    else
    {
        printf("\n The elements in the stack are \n");
        while(ptr!=NULL)
        {
            printf("\n %d",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
}
struct sk *pop(struct sk *top)
{
    struct sk *ptr;
    ptr=top;
    if(top==NULL)
    printf("\n STACK UNDERFLOW \n");
    else
    {
        top=top->next;
    printf("\n THE VALUE BEING DELETED IS :%d \n",ptr->data);
        free(ptr);
    }
    return top;
}