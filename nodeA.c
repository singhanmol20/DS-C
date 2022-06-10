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
            printf("Enter the data for node: ");
            scanf("%d", &num);
            firstnode->num = num;
            firstnode->next = NULL;
            tmp = firstnode;  //tmp here is head node
 
            for (i = 2; i <= n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if (newNode == NULL)
                {
                    printf("Memory can not be allocated.");
                    break;
                }
                else
                {
                    printf("Enter the data of node: ");
                    scanf(" %d", &num);
 
                    newNode->num = num;
                    newNode->next = NULL;
 
                    tmp->next = newNode;
                    tmp = tmp->next;
                }
            }
        }
    }
}
void insert_Node_End(int data)
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
void delete_starting_Node()
{
    struct node *toDelete;

    if(firstnode == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = firstnode;
        firstnode = firstnode->next;
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
            printf("%d\n", tmp->num);
            tmp = tmp->next;
            i++;
        }
    }
}
int main(){
    int n, data;
    printf("Number of nodes?: ");
            scanf("%d", &n);
            createNNode(n);
    printf("\nThe value to be added in the end: ");
            scanf("%d", &data);
            delete_starting_Node();
            insert_Node_End(data);
    printf("The Final list is:\n");
    output();
            return 0;
}