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
void Insert_in_sorted_list(int data){
    struct node *current = firstnode;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num=data;
  if (firstnode == NULL || firstnode->num >= newNode->num)
	{
		newNode->next = firstnode;
		firstnode = newNode;
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
void sortList() {  
        struct node *current = firstnode, *index = NULL;  
        int temp;  
          
        if(firstnode == NULL) {  
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
    printf("The value to be added: ");
            scanf("%d",&data);
            sortList();
            Insert_in_sorted_list(data);
    printf("The list is:\n");
    output();    
return 0;
}