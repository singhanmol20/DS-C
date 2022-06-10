#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b);
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return 1+max(height(N->left), height(N->right));
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* nnode(int data)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 0; 
	return(node);
}

struct Node *rrotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = height(y);
	x->height = height(x);

	return x;
}

struct Node *lrotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = height(x);
	y->height = height(y);

	return y;
}

int getb(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{
	if (node == NULL)
		return(nnode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else 
		return node;

	node->height = height(node);

	int balance = getb(node);


	if (balance > 1 && data < node->left->data)
		return rrotate(node);

	if (balance < -1 && data > node->right->data)
		return lrotate(node);

	if (balance > 1 && data > node->left->data)
	{
		node->left = lrotate(node->left);
		return rrotate(node);
	}

	if (balance < -1 && data < node->right->data)
	{
		node->right = rrotate(node->right);
		return lrotate(node);
	}
	return node;
}
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
struct Node *root = NULL;
root = insert(root, 10);
root = insert(root, 30);
root = insert(root, 90);
root = insert(root, 100);
root = insert(root, 20);
root = insert(root, 41);

printf("tree in preorder: \n");
preOrder(root);

return 0;
}
