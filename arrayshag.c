#include<stdio.h>
 int stack[100],top,n;
void isempty();
void isfull();
void push();
void pop();
void display();
int main()
{
   int choice;
    top=-1;
    printf("Enter the size of the stack \n");
    scanf("%d",&n);
    do
    {
    printf(" \n STACK OPERATIONS USING ARRAYS \n");
    printf("\n ---------------------------- \n");
    printf("1.TO CHECK THE STACK IS EMPTY \n");
    printf("2.TO CHECK THE STACK IS FULL \n");
    printf("3.PUSH \n");
    printf("4.POP \n");
    printf("5.Display \n");
    printf("6.EXit \n");
    printf(" \n ------------------------------- \n");
    
       printf("\n Enter your choice \n");
       scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            isempty();
            break;
            case 2:
            isfull();
            break;
            case 3:
            push();
            break;
            case 4:
            pop();
            break;
            case 5:
            display();
            break;
            case 6:
            printf("EXIT POINT \n");
            break;
            default:
            printf("WRONG CHPOICE \n");
     }
    }
        while(choice!=6);

    return 0;
}
void isempty()
{
    if(top == -1) 
    {
        printf(" \n STACK UNDERFLOW \n");
    }
    else
    {
        printf("\n STACK IS NOT EMPTY \n");
    }
}
void isfull()
{
    if(top == n-1)
    {
      printf(" \n STACK OVERFLOW \n");
    }
    else
    printf("\n STACK IS NOT FULL\n");
}
void push()
{
    int val;
   
    if(top == n-1)
    {
        printf(" \n STACK OVERFLOW \n");
    }
    else
    {
        
         printf(" \n Enter the number to be pushed to stack \n");
        scanf("%d",&val);
        top++;
        stack[top]=val;
    }
}
void pop()
{
    int val;
    if(top ==-1)
    {
        printf(" \n STACK UNDERFLOW \n");
    }
    else
    {
      printf(" \n The popped elements is %d \n",stack[top]);
      top--;
     }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf(" \n STACK IS EMPTY\n");
    }
    else
    {
        printf(" \n THE ELEMENTS IN THE STACK ARE \n");
        for(i=top;i>=0;i--)
        {
            printf("\n");
            printf("%d \n",stack[i]);
        
        }
    }
}