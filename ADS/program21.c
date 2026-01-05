#include <stdio.h> #include <stdlib.h>

typedef struct Node { int data;
struct Node* parent; struct Node* left; struct Node* right;
int color; // 0 for black, 1 for red
} Node;




typedef struct RedBlackTree {
 
Node* root;
} RedBlackTree;

Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node)); if (newNode == NULL) {
printf("Memory allocation error\n"); exit(1);
}
newNode->data = data;
newNode->parent = newNode->left = newNode->right = NULL; newNode->color = 1; // New nodes are initially red
return newNode;
}
RedBlackTree* createRedBlackTree() {
RedBlackTree* newTree = (RedBlackTree*)malloc(sizeof(RedBlackTree)); if (newTree == NULL) {
printf("Memory allocation error\n"); exit(1);
}
newTree->root = NULL; return newTree;
}
void leftRotate(RedBlackTree* tree, Node* x) { Node* y = x->right;
x->right = y->left;
if (y->left != NULL) y->left->parent = x;
y->parent = x->parent; if (x->parent == NULL)
tree->root = y;
else if (x == x->parent->left) x->parent->left = y;
else
x->parent->right = y; y->left = x;
x->parent = y;
}
void rightRotate(RedBlackTree* tree, Node* y) { Node* x = y->left;
y->left = x->right;
if (x->right != NULL) x->right->parent = y;
x->parent = y->parent;


if (y->parent == NULL)
 
tree->root = x;
else if (y == y->parent->left) y->parent->left = x;
else
y->parent->right = x; x->right = y;
y->parent = x;
}
void insertFixup(RedBlackTree* tree, Node* z) {
while (z->parent != NULL && z->parent->color == 1) { if (z->parent == z->parent->parent->left) {
Node* y = z->parent->parent->right; if (y != NULL && y->color == 1) {
z->parent->color = 0;
y->color = 0;
z->parent->parent->color = 1; z = z->parent->parent;
} else {
if (z == z->parent->right) { z = z->parent;
leftRotate(tree, z);
}
z->parent->color = 0; // Black
z->parent->parent->color = 1; // Red rightRotate(tree, z->parent->parent);
}
} else {
Node* y = z->parent->parent->left; if (y != NULL && y->color == 1) { z->parent->color = 0; // Black
y->color = 0; // Black
z->parent->parent->color = 1; z = z->parent->parent;
} else {
if (z == z->parent->left) { z = z->parent; rightRotate(tree, z);
}
z->parent->color = 0;
z->parent->parent->color = 1; leftRotate(tree, z->parent->parent);
}
}




}
 
tree->root->color = 0;
}
void insert(RedBlackTree* tree, int data) { Node* z = createNode(data);
Node* y = NULL; Node* x = tree->root;

while (x != NULL) { y = x;
if (z->data < x->data) x = x->left;
else
x = x->right;
}
z->parent = y;
if (y == NULL){
tree->root = z;
else if (z->data < y->data) y->left = z;
else
y->right = z;

insertFixup(tree, z);
}
Node* findMinValueNode(Node* node) { Node* current = node;
while (current->left != NULL) current = current->left;
return current;
}
void deleteFixup(RedBlackTree* tree, Node* x) { while (x != tree->root && x->color == 0) {
if (x == x->parent->left) { Node* w = x->parent->right; if (w->color == 1) {
w->color = 0;
x->parent->color = 1; leftRotate(tree, x->parent); w = x->parent->right;
}
if (w->left->color == 0 && w->right->color == 0) { w->color = 1;
x = x->parent;
} else {
if (w->right->color == 0) {


w->left->color = 0;
 
w->color = 1; rightRotate(tree, w); w = x->parent->right;
}
 




}
} else {
 
w->color = x->parent->color; x->parent->color = 0;
w->right->color = 0; leftRotate(tree, x->parent); x = tree->root;
 
Node* w = x->parent->left; if (w->color == 1) {
w->color = 0;
x->parent->color = 1; rightRotate(tree, x->parent); w = x->parent->left;
}
if (w->right->color == 0 && w->left->color == 0) { w->color = 1;
x = x->parent;
} else {
if (w->left->color == 0) { w->right->color = 0;
w->color = 1; leftRotate(tree, w); w = x->parent->left;
}
w->color = x->parent->color; x->parent->color = 0;
w->left->color = 0; rightRotate(tree, x->parent); x = tree->root;
}
}
}
x->color = 0;
}
void transplant(RedBlackTree* tree, Node* u, Node* v) { if (u->parent == NULL) {
tree->root = v;
} else if (u == u->parent->left) { u->parent->left = v;
} else {



u->parent->right = v;
 
}
if (v != NULL) {
v->parent = u->parent;
}
}
void delete(RedBlackTree* tree, int data) { Node* z = tree->root;
while (z != NULL && z->data != data) { if (data < z->data)
z = z->left; else
z = z->right;
}

if (z == NULL) {
printf("Node not found in the tree\n"); return;
}
Node* y = z;
Node* x;
int yOriginalColor = y->color;

if (z->left == NULL) { x = z->right;
transplant(tree, z, z->right);
} else if (z->right == NULL) { x = z->left;
transplant(tree, z, z->left);
} else {
y = findMinValueNode(z->right); subtree yOriginalColor = y->color;
x = y->right;

if (y->parent == z) { x->parent = y;
} else {
transplant(tree, y, y->right); y->right = z->right;
y->right->parent = y;
}

transplant(tree, z, y); y->left = z->left;



y->left->parent = y;
 
y->color = z->color;
}
free(z);

if (yOriginalColor == 0) { deleteFixup(tree, x);
}
}
void inOrderTraversal(Node* root) { char c[2][6]={"BLACK","RED"};
if (root != NULL) { inOrderTraversal(root->left);
printf("%d,%s -> ", root->data, c[root->color]); inOrderTraversal(root->right);
}
}
void freeMemory(Node* root) { if (root == NULL)
return; freeMemory(root->left); freeMemory(root->right); free(root);
}

int main() {
int choice,value;
RedBlackTree* tree = createRedBlackTree(); printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit"); do
{
printf("\n\nEnter your choice: "); scanf("%d",&choice); switch(choice)
{
case 1: printf("Enter the value to be insert: "); scanf("%d",&value);
insert(tree, value); break;
case 2: printf("Enter the value to be deleted: "); scanf("%d",&value);
delete(tree, value); break;


case 3: inOrderTraversal(tree->root);
 
break;
case 4: freeMemory(tree->root); break;
default: printf("\nWrong selection!!! Try again!!!");
}
}while(choice!=4); return(0);
}
