#include <stdio.h>
#include<stdlib.h>
int f = -1, r = -1;
int Isempty()
{
    if (f > r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Isfull(int n)
{
    if (r + 1 == n)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int q[], int n)
{
    int item;
    if (Isfull(n))
    {
        printf("Queue is full");
        return;
    }
    printf("Enter the number: ");
    scanf("%d", &item);
    
    
    if (f == -1 && r == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = r + 1;
    }

    q[r] = item;

    
}

void display(int q[])
{

    for (int i = f; i <= r; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void dequeue(int q[])
{

    if (Isempty())
    {
        printf("Queue is empty: ");
    }
    else
    {
        printf("%d removed\n", q[f]);
        f++;
    }
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
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(1);
        
        default:
            break;
        }
    }
    return 0;
}