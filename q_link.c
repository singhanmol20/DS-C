#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    
}*head=NULL,*f=NULL,*r=NULL;

void enqueue(int n)
{
    
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Queue is full");
    }
    else
    {
        newnode->data=n;
        newnode->next=NULL;
    }
    if(f==NULL)
    {
        f=r=newnode;
    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}

int dequeue()
{
    int i=-1;
    struct node* p;
    if(f==NULL)
    {
        return i;
    }
    else
    {
        p=f;
        f=f->next;
        i=p->data;
        free(p);
    }
    return i;
}
void display()
{
    struct node *tmp;
    if (f == NULL)
        printf("List is empty.");
    else
    {
        tmp = f;
        int i = 1;
        while (tmp != NULL)
        {
            printf("%d\n", tmp->data);
            tmp = tmp->next;
            i++;
        }
    }
}
int main()
{   int choice;
    int n;
   while (1)

    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the number: ");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        
        default:
            break;
        }
    }
    return 0;
}