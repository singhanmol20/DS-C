#include <stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
#define MAX 5
int Q[MAX];
void insert(int item)
{ 
    if((front==0 && rear==MAX-1)||(front==rear+1))
    {
        printf("\nOverflow\n");
        return;
    }
    if(front==-1)
    front=0;
    rear=(rear+1)%MAX;
    Q[rear]=item;
}
void delete()
{
    int item;
    if(front==-1)
    {
        printf("\nUnderflow\n");
    }
    item=Q[front];
    if(front==rear)
    {
        front=rear+1;
    }
    else {
        front=(front+1)%MAX;
      
    }
}
void display()
{ int i;
    if(front==-1)
    {
        printf("No elements\n");
        return;
    }
    for(i=front;i!=rear;i=(i+1)%MAX)
    {
    printf("%d ",Q[i]);
    }
    printf("%d ",Q[rear]);
}
int main()
{
 int choice,num; 
 while(1)
 { 
      printf(" \n Enter 1: To insert\n Enter 2: To delete\n Enter 3: To display\n Enter 4: To exit\n");
      scanf("%d",&choice); 
     switch(choice)
     {
         case 1: 
         printf("\nEnter your number\n");
         scanf("%d",&num);
         insert(num);
         break;
         case 2:
         delete();
         printf("Deleted successfully");
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
}