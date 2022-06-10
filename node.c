#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
} * firstnode;

void output()
{
    struct node *tmp;
    tmp = firstnode;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
    }
}
void insert_beginning(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->num = data;
    newnode->next = firstnode;
    firstnode = newnode;
}

int main()
{
    struct node *newNode, *tmp;
    firstnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the firstnode data\n");
    scanf("%d", &firstnode->num);
    firstnode->next = NULL;
    tmp = firstnode;
    for (int i = 0; i < 6; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("enter node data\n");
        scanf("%d", &newNode->num);
        newNode->next = NULL;
        tmp->next = newNode;
        tmp = tmp->next;
    }
    int d;
    printf("enter the data to be added in the beginning");
    scanf("%d", &d);
    insert_beginning(d);
    printf("the node data are displayed here\n");
    output();
}