#include <stdio.h>
#include<stdlib.h>
int f = -1, r = -1;

void enqueue(int q[], int n)
{

      if((r+1)%n==f)
    {
        printf("Queue is full\n");
        return;
    }
    if(f==-1){ f=0;}
    r=(r+1)%n;
    printf("Enter a value: ");
    
    scanf("%d",&q[r]);
    
}

void display(int q[],int n)
{
if(f==-1 && r==-1)
    {
        return;
    }
    
    if(f<=r)
    {
        printf("%d",q[f]);
        for (int  i=f+1; i <=r; i++)
       {
        printf("->%d",q[i]);
       }
       printf("\n");
    }
    else if(f>r)
    {
       
        printf("%d",q[f]);
        for(int i=f+1;i<n;i++)
        {
            printf("->%d",q[i]);
        }
        for(int i=0;i<=r;i++)
        {
           printf("->%d",q[i]);
        }
         printf("\n");
    }

}

void dequeue(int q[],int i)
{

   if(r==f)
    {
        printf("Queue is empty\n");
        f=-1;
        r=-1;
        return;
    }

    
    f=(f+1)%i;
}

int main()
{
    int n, choice = 0;
    printf("Enter size: ");
    scanf("%d", &n);
    int queue[n];

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
            enqueue(queue, n);
            break;
        case 2:
            dequeue(queue,n);
            break;
        case 3:
            display(queue,n);
            break;
        case 4:
            exit(1);
        
        default:
            break;
        }
    }
    return 0;
}