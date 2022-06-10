#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
} * head;

void createnodes(int n)
{
    if (n != 0)
    {
        struct node *newnode, *temp;
        int num;
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            printf(" Memory can not be allocated.");
        }
        else
        {
            printf("Enter the data for node 1 : ");
            scanf("%d", &num);
            head->data = num;
            head->next = NULL;
            head->prev = NULL;
            temp = head;

            for (int i = 2; i <= n; i++)
            {
                newnode = (struct node *)malloc(sizeof(struct node));

                printf("Enter the data for node %d : ", i);
                scanf(" %d", &num);

                newnode->data = num;
                newnode->prev = temp;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
}
void insert_at_a_given_value()
{
    struct node *ptr, *temp;
    int value, loc;
    ptr = (struct node *)malloc(sizeof(struct node));

    temp = head;
    printf("Enter the location");
    scanf("%d", &loc);
    for (int i = 1; i < loc - 1; i++)
    {
        temp = temp->next;
    }
    printf("Enter value");
    scanf("%d", &value);
    ptr->data = value;
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next = ptr;
    temp->next->prev = ptr;
}

void display()
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    int option, i;
    while (1)
    {
        printf("\n1. Create Nodes");
        printf("\n2. Insert before a given value");
        printf("\n3. Delete the middle node");
        printf("\n4. Display");
        printf("\n5.Exit\n");

        printf("Enter the option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("number of node: ");
            scanf("%d", &i);
            createnodes(i);
            break;
        case 2:
            insert_at_a_given_value();
            break;
        case 3:
            printf("");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        }
    }
}