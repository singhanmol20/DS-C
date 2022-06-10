#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
} * firstnode;

void createNNode(int n)
{
    if (n != 0)
    {
        struct node *newNode, *tmp;
        int num, i;
        firstnode = (struct node *)malloc(sizeof(struct node));

        if (firstnode == NULL)
            printf(" Memory can not be allocated.");
        else
        {
            printf("Enter the data for node 1 : ");
            scanf("%d", &num);
            firstnode->num = num;
            firstnode->next = NULL;
            tmp = firstnode;

            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                printf("Enter the data for node %d : ", i);
                scanf(" %d", &num);

                newNode->num = num;
                newNode->next = NULL;

                tmp->next = newNode;
                tmp = tmp->next;
            }
        }
    }
}
void output()
{
    struct node *tmp;
    if (firstnode == NULL)
        printf("List is empty.");
    else
    {
        tmp = firstnode;
        int i = 1;
        while (tmp != NULL)
        {
            printf("The data in Node No.%d = %d\n", i, tmp->num);
            tmp = tmp->next;
            i++;
        }
    }
}
void insertNodeAtBeginning(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Unable to allocate memory.");
    else
    {
        newNode->num = data;
        newNode->next = firstnode;
        firstnode = newNode;
    }
}

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
        printf("Unable to allocate memory.");
    else
    {
        newNode->num = data;
        newNode->next = NULL;
        temp = firstnode;

        //going to the last node
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}
void insertNodeAtN(int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    int i;
    struct node *temp = firstnode;
    if (position == 1)
    {
        newNode->next = temp;
        firstnode = newNode;
        return;
    }
    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main()
{
    int n, data, opt, abcd;

    while (1)
    {
        printf("\n1. Create Nodes");
        printf("\n2. Insert at beginning");
        printf("\n3. Insert at end");
        printf("\n4. Display list");
        printf("\n5. Insert Node at nth position");
        printf("\n6. Exit \n");

        printf("Enter the option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("How many nodes do you want? ");
            scanf("%d", &n);
            createNNode(n);
            break;
        case 2:
            printf("\nEnter data to insert at beginning of the list: ");
            scanf("%d", &data);
            insertNodeAtBeginning(data);
            break;
        case 3:
            printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            break;
        case 4:
            output();
            break;
        case 5:
        
            printf("Enter position");
            scanf("%d", &abcd);
            printf("\nEnter data: ");
            scanf("%d", &data);
            insertNodeAtN(data, abcd) ;
            break;
        case 6:
            exit(0);
            break;
        }
    }

    return 0;
}
