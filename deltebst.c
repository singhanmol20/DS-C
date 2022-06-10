#include<stdio.h>
#include<stdlib.h> 
//0=left,1=right;
struct node{
    int data;
    struct node *left,*right;
};
struct node* mnode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
void add(int n,struct node *root){
    if(n>root->data){
        if(root->right==NULL){
            struct node *nnode = malloc(sizeof(struct node));
            nnode->data=n;
            nnode->left=NULL;
            nnode->right=NULL;
            root->right=nnode;
        }
        else{
            add(n,root->right);
        }
    }
    else{
        if(root->left==NULL){
            struct node *nnode = malloc(sizeof(struct node));
            nnode->data=n;
            nnode->left=NULL;
            nnode->right=NULL;
            root->left=nnode;
        }
        else{
            add(n,root->left);
        }
    }
}
void printinline(struct node *root){
    if (root != NULL) {
        printinline(root->left);
        printf("%d ", root->data);
        printinline(root->right);
    }
}
struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
        return root;
 
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = mnode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    int n,val;
    struct node *root;
    root = malloc(sizeof (struct node));
    root->left=NULL;
    root->right=NULL;
    while (1)
    {
        printf("1. add number\n2. display node in inline\n3. delete.\n4.exit.\noption: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1: 
            printf("enter the value to be added: ");
            scanf("%d",&val);
            add(val,root);
            break;
        case 2:
            printf("--> ");
            printinline(root);
            printf("\n");
            break;
        case 3:
             printf("enter the value to be deleted: ");
            scanf("%d",&val);
            root = deleteNode(root,val);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;

}
