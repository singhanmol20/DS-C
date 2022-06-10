#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node *start=NULL;
struct Node
{
	int data;
	struct Node *next;
};
void insert_at_begin(int x)
{
	struct Node *t;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	t->data=x;
	t->next=start;
	start=t;
}
void insert_at_end(int x)
{
	struct Node *t,*temp;
	t=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(start==NULL)
	{
		start=t;
		start->data=x;
		start->next=NULL;
		return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=t;
	t->data=x;
	t->next=NULL;
}
void move_node(){
	
}
void display()
{
	struct Node *t;
	if(start==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	printf("No of elements: %d\n",count);
	printf("Elements are: ");
	t=start;
	while(t->next!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("%d ",t->data);
	printf("\n\n");
}
int main()
{// merge the two sorted list 
	int ch,data;
	while(1)
	{
		printf("---LINKED LIST PROGRAMS---\n");
		printf("1. INSERT AT BEGINING\n");
        printf("2. INSERT IN THE END\n");
		printf("3. DISPLAY LIST\n");
		printf("4. EXIT\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_begin(data);
		}
		else if(ch==2){
            printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_end(data);
        }
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			break;
		}
		else
		{
			printf("Wrong choice!!!\n");
		}
	}
}