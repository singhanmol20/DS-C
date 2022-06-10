#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;

NODE insertRear(NODE first)
{
    NODE temp =NULL,cur=NULL;
    int item;
    temp=(NODE)malloc(sizeof(struct node));
    
if(temp==NULL)
{
        printf("\nUnable to allocate memory");
        return first;
} 
    printf("\nEnter an element");
    scanf("%d",&item);
    temp->info=item;
    temp->link=NULL;
    
    if (first==NULL)
    
        first=temp;
    else
    {
        cur=first;
        
        while(cur->link != NULL)
         cur=cur->link;
         
         cur->link=temp;
    }
    return first;
}

void display(NODE first)
{
    NODE cur = NULL;
    
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    cur = first;
    while (cur != NULL)
    {
        printf("%d",cur -> info);
        cur = cur -> link;
    }
}

int main()
{
    NODE first = NULL;
    int choice=0;
    
    while (1)
    {
        printf("\n 1.insert at rear end");
        printf("\n 2. dispaly\n");
        
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1: first=insertRear(first);
                    break;
            case 2:display(first);
                    break;
                default:printf("the program has terminated");
                exit(0);
        }
        
    }
    return 0;
}