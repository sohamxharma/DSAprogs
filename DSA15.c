//simple program on AVL

#include<stdio.h>
#include<stdlib.h>
struct Node
{
int k;
struct Node *left;
struct Node *right;
int height;
};
int max(int x, int y);
int height(struct Node *N)
{
if (N == NULL)
return 0;
return N->height;
}
int max(int x, int y)
{
return (x > y)? x : y;
}
struct Node* newNode(int k)
{
struct Node* node = (struct Node*)
malloc(sizeof(struct Node));
node->k   = k;
node->left   = NULL;
node->right  = NULL;
node->height = 1;
return(node);
}
struct Node *rightrotate(struct Node *y)
{
struct Node *x = y->left;
struct Node *T2 = x->right;
x->right = y;
y->left = T2;
y->height = max(height(y->left), height(y->right))+1;
x->height = max(height(x->left), height(x->right))+1;
return x;
}
struct Node *lftRotate(struct Node *x)
{
struct Node *y = x->right;
struct Node *T2 = y->left;
y->left = x;
x->right = T2;
x->height = max(height(x->left), height(x->right))+1;
y->height = max(height(y->left), height(y->right))+1;
return y;
}
// obtaining bal
int obal(struct Node *N)
{
if (N == NULL)
return 0;
return height(N->left) - height(N->right);
}
struct Node* insert(struct Node* node, int k)
{
if (node == NULL)
return(newNode(k));
if (k < node->k)
node->left  = insert(node->left, k);
else if (k > node->k)
node->right = insert(node->right, k);
else
return node;
node->height = 1 + max(height(node->left),
height(node->right));
int bal = obal(node);
if (bal > 1 && k < node->left->k)
return rightrotate(node);
if (bal < -1 && k > node->right->k)
return lftRotate(node);
if (bal > 1 && k > node->left->k)
{
node->left =  lftRotate(node->left);
return rightrotate(node);
}
if (bal < -1 && k < node->right->k)
{
node->right = rightrotate(node->right);
return lftRotate(node);
}
return node;
}
// node of minimum value
struct Node * minode(struct Node* node)
{
struct Node* tempo = node;

while (tempo->left != NULL)
tempo = tempo->left;
return tempo;
}
struct Node* nodedeletor(struct Node* base, int k)
{
if (base == NULL)
return base;
if ( k < base->k )
base->left = nodedeletor(base->left, k);
else if( k > base->k )
base->right = nodedeletor(base->right, k);
else
{
if( (base->left == NULL) || (base->right == NULL) )
{
struct Node *temp = base->left ? base->left :
base->right;
if (temp == NULL)
{
temp = base;
base = NULL;
}
else
*base = *temp;
free(temp);
}
else
{
struct Node* temp = minode(base->right);
base->k = temp->k;
base->right = nodedeletor(base->right, temp->k);
}
}
if (base == NULL)
return base;
base->height = 1 + max(height(base->left),
height(base->right));
int bal = obal(base);
if (bal > 1 && obal(base->left) >= 0)
return rightrotate(base);
if (bal > 1 && obal(base->left) < 0)
{
base->left =  lftRotate(base->left);
return rightrotate(base);
}
if (bal < -1 && obal(base->right) <= 0)
return lftRotate(base);
if (bal < -1 && obal(base->right) > 0)
{
base->right = rightrotate(base->right);
return lftRotate(base);
}
return base;
}
void preOrdered(struct Node *base)
{
if(base != NULL)
{
printf("%d ", base->k);
preOrdered(base->left);
preOrdered(base->right);
}
}
int main()
{
struct Node *base = NULL;
base = insert(base, 9);
base = insert(base, 27);

printf("The output of an AVL tree in preOrdered form: \n");
preOrdered(base);
printf("\n");
base = nodedeletor(base, 9);
base = nodedeletor(base, 72);
printf("The tree in preOrdered traversal outputs after deletion: \n");
preOrdered(base);
printf("\n");
base = insert(base, 1);
base = insert(base, 36);
printf("The tree in preOrdered traversal outputs 2 more inserts: \n");
preOrdered(base);
printf("\n");
return 0;
}