#include <stdio.h> 
#include <stdlib.h> 
struct node {
int data;
struct node *left, *right;
};
struct node* createNode(int value) {
struct node* newNode = (struct node*)malloc(sizeof(struct node)); newNode->data = value;
newNode->left = newNode->right = NULL; return newNode;
}

struct node* insert(struct node* root, int value) {
 if (root == NULL)
return createNode(value);

if (value < root->data)
root->left = insert(root->left, value);
 else if (value > root->data)
root->right = insert(root->right, value);
return root;
}

struct node* findMin(struct node* root) 
{ while (root->left != NULL)
root = root->left;

return root;
}

struct node* deleteNode(struct node* root, int value) {
 
if (root == NULL) return root;
if (value < root->data)
root->left = deleteNode(root->left, value); else if (value > root->data)
root->right = deleteNode(root->right, value); else {
// Node with one or no child if (root->left == NULL) {
struct node* temp = root->right;
free(root); return temp;
}
else if (root->right == NULL) { 
struct node* temp = root->left; 
free(root);
return temp;
}

// Node with two children
struct node* temp = findMin(root->right); 
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
void inorder(struct node* root) { if (root != NULL) {
inorder(root->left); printf("%d ", root->data); inorder(root->right);
}
}
void preorder(struct node* root) { if (root != NULL) {
printf("%d ", root->data); preorder(root->left); preorder(root->right);
}
}


void postorder(struct node* root) { if (root != NULL) {
postorder(root->left); postorder(root->right);
 
printf("%d ", root->data);
}
}
int main() {
struct node* root = NULL; int choice, value;
do {
printf("\n--- Binary Search Tree Menu ---\n"); printf("1. Insert\n");
printf("2. Delete\n");
printf("3. Inorder Traversal\n"); printf("4. Preorder Traversal\n"); printf("5. Postorder Traversal\n"); printf("6. Exit\n");
printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) { case 1:
printf("Enter value to insert: "); scanf("%d", &value);
root = insert(root, value); break;
case 2:
printf("Enter value to delete: "); scanf("%d", &value);
root = deleteNode(root, value); break;

case 3:
printf("Inorder Traversal: "); inorder(root);
printf("\n"); break;

case 4:
printf("Preorder Traversal: "); preorder(root);
printf("\n"); break;



case 5:
printf("Postorder Traversal: "); postorder(root);
printf("\n");
 
break; case 6:
exit(0); default:
printf("Invalid choice!\n");
} } while (choice != 6); return 0;
}
