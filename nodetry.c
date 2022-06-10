#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
} * firstnode1, * firstnode2;

void createNNode1(int n)
{
    if (n != 0)
    {
        struct node *newNode, *tmp;
        int num, i;
        firstnode1= (struct node *)malloc(sizeof(struct node));
 
        if (firstnode1== NULL)
            printf(" Memory can not be allocated.");
        else
        {
            printf("Enter the data for node 1 : ");
            scanf("%d", &num);
            firstnode1->num = num;
            firstnode1->next = NULL;
            tmp = firstnode1;  
 
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
}
void createNNode2(int n)
{
    if (n != 0)
    {
        struct node *newNode, *tmp;
        int num, i;
        firstnode2= (struct node *)malloc(sizeof(struct node));
 
        if (firstnode2== NULL)
            printf(" Memory can not be allocated.");
        else
        {
            printf("Enter the data for node 1 : ");
            scanf("%d", &num);
            firstnode2->num = num;
            firstnode2->next = NULL;
            tmp = firstnode2;  
 
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
}
void output1()
{
    struct node *tmp;
    if (firstnode1== NULL)
        printf("List is empty.");
    else
    {
        tmp = firstnode1;
        int i = 1;
        while (tmp != NULL)
        {
            printf("The data in Node No.%d = %d\n", i, tmp->num);
            tmp = tmp->next;
            i++;
        }
    }
}
void output2()
{
    struct node *tmp;
    if (firstnode2== NULL)
        printf("List is empty.");
    else
    {
        tmp = firstnode2;
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
        newNode->next = firstnode1;
        firstnode1= newNode;
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
        temp = firstnode1;
 
        //going to the last node
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
 
        temp->next = newNode;
    }
}
void insertNodeAtN(int data, int position)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->num=data;
    int i;
    struct node *temp=firstnode1;
    if (position==1)
    {
        ptr->next=temp;
        firstnode1=ptr;
        return;
    }
    for(i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
 
}
void sortList() {  
        //Node current will point to head  
        struct node *current = firstnode1, *index = NULL;  
        int temp;  
          
        if(firstnode1== NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
         
                index = current->next;  
                  
                while(index != NULL) {  
                     
                    if(current->num > index->num) {  
                        temp = current->num;  
                        current->num = index->num;  
                        index->num = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    }  

void Insert_in_sorted_list(int data){
    struct node *current = firstnode1;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num=data;
  if (firstnode1== NULL || firstnode1->num >= newNode->num)
	{
		newNode->next = firstnode1;
		firstnode1= newNode;
		return;
	}

    else
    { 
       while (current->next != NULL && current->next->num < newNode->num)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;

    }
}
void deletefirstnode1()
{
    struct node *toDelete;

    if(firstnode1== NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = firstnode1;
        firstnode1= firstnode1->next;
    }
}
//void merge(){

//}
int main()
{
    int n, data, opt, pos;
 
    while (1)
    {
        printf("\n1. Create List 1");
        printf("\n2. Create List 2");
        printf("\n3. Insert at beginning");
        printf("\n4. Insert at end");
        printf("\n5. Insert at nth position");
        printf("\n6. Display list");
        printf("\n7. Sorted nodes");
        printf("\n8. Insert a value in sorted list");
        printf("\n9. To add a node at the end and delete a node at the beginning");
        printf("\n10. Exit \n");
 
        printf("Enter the option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("How many nodes do you want? ");
            scanf("%d", &n);
            createNNode1(n);
            break;
        case 2:
            printf("How many nodes do you want? ");
            scanf("%d", &n);
            createNNode2(n);
            break;
        case 3:
            printf("\nEnter data to insert at beginning of the list: ");
            scanf("%d", &data);
            insertNodeAtBeginning(data);
            break;
        case 4:
            printf("\nEnter data to insert at end of the list: ");
            scanf("%d", &data);
            insertNodeAtEnd(data);
            break;
        case 5:
            printf("\nAt what position you want to insert the nodes? ");
            scanf("%d", &pos);
            printf("\nEnter data to insert at %d position: ", pos);
            scanf("%d", &data);
            insertNodeAtN(data, pos);
            break;
        case 6:
            output1();
            printf("\n");
            printf("The second list is \n");
            output2();
            break;
        case 7:
            sortList();
            break;
        case 8:
            printf("Enter the value to be added in the list: ");
            scanf("%d",&data);
            sortList();
            Insert_in_sorted_list(data);
            break;
        case 9:
            printf("\nEnter data to insert at end of the list (deletes the starting node): ");
            scanf("%d", &data);
            deletefirstnode1();
            insertNodeAtEnd(data);
            break;
        case 10:
            exit(0);
            break;
        case 11:
            // merge();
            break;
        }
    }
 
    return 0;
}