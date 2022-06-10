#include<stdio.h>
#include<stdlib.h> 
#include<ctype.h>  
#include<string.h>

struct bst
{
    int val;
    struct bst *right;
    struct bst *left;
};
void printinline(struct bst *root){
    if(root->left!=NULL){
        printinline(root->left);
    }
    printf("  %d,",root->val);
    if(root->right!=NULL){
        printinline(root->right);
    }
}
void printpost(struct bst *root){
    printf("  %d,",root->val);
    if(root->left!=NULL){
        printpost(root->left);
    }
    
    if(root->right!=NULL){
        printpost(root->right);
    }   
}
void printpre(struct bst *root){
    
    if(root->left!=NULL){
        printpre(root->left);
    }
    
    if(root->right!=NULL){
        printpre(root->right);
    }

    printf("  %d,",root->val);
}
void add(int n,struct bst *root){
    if(n>root->val){
        if(root->right==NULL){
            struct bst *nnode = malloc(sizeof(struct bst));
            nnode->val=n;
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
            struct bst *nnode = malloc(sizeof(struct bst));
            nnode->val=n;
            nnode->left=NULL;
            nnode->right=NULL;
            root->left=nnode;
        }
        else{
            add(n,root->left);
        }
    }
}
int main(){
    int n,val;
    struct bst *root;
    root = malloc(sizeof (struct bst));
    root->left=NULL;
    root->right=NULL;
    while (n!=5)
    {
        printf("1. add number\n2.display bst in inline\n3. display bst in preorder\n4.display bst in post order.\n5.exit.\n option: ");
        scanf("%d",&n);
        if(n==1){
            printf("enter the value to be added: ");
            scanf("%d",&val);
            add(val,root);
        }
        else if(n==2){
            printf("--> ");
            printinline(root);
            printf("\n");
        }
        else if(n==3){
            printf("--> ");
            printpre(root);
            printf("\n");
        }
        else if(n==4){
            printf("--> ");
            printpost(root);
            printf("\n");
        }else{
            printf("exit.");
        }

    }
    return 0;

}
