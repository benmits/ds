#include <stdio.h> #include <stdlib.h> typedef struct Node {
int data;
struct Node* next;
} Node;
Node* head = NULL; Node* createNode(int data); void insertEnd(int data); void deleteBeginning(); void deleteEnd();
void deleteByValue(int key); void traverse();
void freeList();
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node)); if (newNode == NULL) {
printf("Error: Memory allocation failed\n"); exit(1);
}
newNode->data = data; newNode->next = NULL; return newNode;
}
void insertEnd(int data) {
Node* newNode = createNode(data); if (head == NULL) {
head = newNode;
printf("Inserted %d (List was empty).\n", data); return;
}
Node* temp = head;
while (temp->next != NULL) { temp = temp->next;
}
temp->next = newNode; printf("Inserted %d at the end.\n", data);
}
void traverse() {
 

Node* temp = head; if (head == NULL) {
printf("The list is empty.\n"); return;
}
printf("Linked List: "); while (temp != NULL) {
printf("%d -> ", temp->data); temp = temp->next;
}
printf("NULL\n");
}
void deleteBeginning() { if (head == NULL) {
printf("Cannot delete from the beginning. The list is empty.\n"); return;
}
Node* temp = head; head = head->next;
printf("Deleted from beginning: %d\n", temp->data); free(temp);
}
void deleteEnd() {
if (head == NULL) {
printf("Cannot delete from the end. The list is empty.\n"); return;
}
if (head->next == NULL) {
printf("Deleted from end: %d\n", head->data); free(head);
head = NULL; return;
}
Node* temp = head; Node* prev = NULL;
while (temp->next != NULL) { prev = temp;
temp = temp->next;
}
prev->next = NULL;
printf("Deleted from end: %d\n", temp->data); free(temp);
}
 
void deleteByValue(int key) { Node* current = head; Node* prev = NULL;
if (current != NULL && current->data == key) { head = current->next;
printf("Deleted node with value %d (head).\n", key); free(current);
return;
}
while (current != NULL && current->data != key) { prev = current;
current = current->next;
}
if (current == NULL) {
printf("Value %d not found in the list. Cannot delete.\n", key);

return;
}
prev->next = current->next;
printf("Deleted node with value %d.\n", key); free(current);
}
void freeList() { Node* temp;
while (head != NULL) { temp = head;
head = head->next; free(temp);
}
}
int main() {
int choice, data, key;
printf("1. Insert (Creation)\n"); printf("2. Delete from Beginning\n"); printf("3. Delete from End\n");
printf("4. Delete by Value (Particular Location)\n"); printf("5. Traverse (Display List)\n");
printf("6. Exit\n"); while (1) {
printf("Enter your choice: "); scanf("%d", &choice); switch (choice) {
case 1:
printf("Enter data to insert: "); scanf("%d", &data);
 

insertEnd(data); break;
case 2:
deleteBeginning(); break;
case 3:
deleteEnd(); break;
case 4:
printf("Enter value to delete: "); scanf("%d", &key); deleteByValue(key);
break; case 5:
traverse(); break;
case 6:
freeList();
printf("Exiting program.\n"); exit(0);
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
