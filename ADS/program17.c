#include <stdio.h> #include <stdlib.h> void create(void); void insertbeg(void); void insertend(void); void display(void); void traverse();
void deletefirst(void); void deletelast(void); struct node {
int data;
struct node *next; struct node *prev;
};
struct node *head = NULL; void main() {
int ch; do {
printf("\n\n1.	Creation\n2.	Insertion	at	beginning\n3.	Insertion	at	end\n4. Display\n5. Traverse\n6. Delete from beginning\n7. Delete from end\n8. Exit"); printf("\nEnter your choice: ");
scanf("%d", &ch); switch (ch) {
case 1: create(); break; case 2: insertbeg();break; case 3: insertend(); break;
 


case 4:display(); break; case 5:traverse(); break; case 6:deletefirst(); break; case 7:deletelast(); break; case 8:exit(0); break;
default:printf("Invalid choice. Please try again.");
}
} while (ch != 8);
}
void create() {
struct node *temp, *newnode, *first; int val, num;
printf("\nEnter the value to be inserted: "); scanf("%d", &val);
first = (struct node *)malloc(sizeof(struct node)); first->data = val;
first->next = NULL; first->prev = NULL; head = first;
temp = head;
printf("\nEnter the number of nodes to be created: "); scanf("%d", &num);
for (int i = 1; i < num; i++) {
newnode = (struct node *)malloc(sizeof(struct node)); printf("\nEnter the value to be inserted: "); scanf("%d", &val);
newnode->data = val; newnode->next = NULL; newnode->prev = temp; temp->next = newnode; temp = temp->next;
}
 

printf("\nDoubly Linked List created successfully");
}
void insertbeg() {
struct node *newnode; int val;
newnode = (struct node *)malloc(sizeof(struct node)); printf("\nEnter the value to be inserted: ");
scanf("%d", &val); newnode->data = val; newnode->next = head; newnode->prev = NULL; if (head != NULL) {
head->prev = newnode;
}
head = newnode; printf("\nSuccessful");
}

void insertend() {
struct node *newnode; int val;
newnode = (struct node *)malloc(sizeof(struct node)); printf("\nEnter the value to be inserted: "); scanf("%d", &val);
newnode->data = val; newnode->next = NULL;
 

if (head == NULL) { newnode->prev = NULL; head = newnode;
} else {
struct node *ptr = head; while (ptr->next != NULL) {
ptr = ptr->next;
}
ptr->next = newnode;

newnode->prev = ptr;
}
printf("\nSuccessful");
}

void display() { struct node *ptr;
if (head == NULL) { printf("\nList empty!!!");
} else {
ptr = head;
while (ptr != NULL) { printf("%d <-> ", ptr->data); ptr = ptr->next;
}
printf("NULL");
}
}
 

void traverse() { struct node *ptr;
if (head == NULL) { printf("\nList empty!!!");
} else {
printf("\nElements in the list (forward traversal): "); ptr = head;
while (ptr != NULL) { printf("%d ", ptr->data); ptr = ptr->next;
}
printf("\n");
}
}
void deletefirst() {
if (head == NULL) {
printf("\nList empty, nothing to delete."); return;
}
struct node *temp = head; head = head->next;
if (head != NULL) { head->prev = NULL;
}
free(temp);
printf("\nFirst node deleted successfully.");
}
 

void deletelast() {
if (head == NULL) {
printf("\nList empty, nothing to delete."); return;
}
if (head->next == NULL) { free(head);
head = NULL;
printf("\nLast node deleted successfully (list is now empty)."); return;
}
struct node *ptr = head; while (ptr->next != NULL) {
ptr = ptr->next;
}
ptr->prev->next = NULL; free(ptr);
printf("\nLast node deleted successfully.");
}
