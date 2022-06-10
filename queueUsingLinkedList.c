// Implement circular queue using arrays
#include <stdio.h>
#include <stdlib.h>

//haven't used GLOBAL variables, instead passed variables as pointers in the functions

int isFull(int front, int rear, int size)
{
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty(int front, int rear)
{
    if (front == rear)
        return 1;
    else
        return 0;
}
void enqueue(int arr[], int size, int element, int *front, int *rear)
{
    if (isFull(*front, rear, size))
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = ((*rear + 1) % size);
        arr[*rear] = element;
        printf("\n Inserted -> %d", element);
    }
}

void dequeue(int arr[], int size, int *front, int *rear)
{
    if (isEmpty(front, rear))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        if (front == -1)
            front = 0;
        printf("\n Deleted -> %d", arr[*front]);
        front = ((*front + 1) % size);
    }
}
int main()
{
    int front = -1, rear = -1, size, element, choice;
    printf("Enter the size of the ciruclar queue: ");
    scanf("%d", &size);
    int queue[size];
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. output\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be enqueued: ");
            int element;
            scanf("%d", &element);
            enqueue(queue, size, element, &front, &rear);
            break;
        case 2:
            dequeue(queue, size, front, rear);
            break;
        case 3:
            // output(queue, size);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}