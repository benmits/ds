#include <stdio.h> #include <stdlib.h> void create(void); void search(void); void display(void); void counts();
void traverse(); struct node {
int data;
struct node *next; struct node *prev;
};
struct node *head = NULL void main() {
int ch;
printf("\n\n1. Creation\n2. Searching\n3. Display\n4. Count of nodes\n5. Traverse\n6. Exit");
do {
printf("\nEnter your choice: "); scanf("%d", &ch);
switch (ch){ case 1: create();
break;
case 2:search(); break; case 3:display(); break; case 4:counts(); break; case 5:traverse(); break; case 6: exit(0);
break; default:
printf("Invalid choice. Please try again.");
}
} while (ch != 6);
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
newnode->data = val; newnode->next = NULL; newnode->prev = temp; temp->next = newnode;
temp = temp->next;
}
printf("\nDoubly Linked List created successfully");
}
void search() { struct node *ptr; int val;
printf("\nEnter the value to be searched: "); scanf("%d", &val);
int count = 0;
if (head == NULL) { printf("\nList empty!!!");
} else {
int flag = 0, c1; ptr = head;
while (ptr != NULL) { count++;
if (ptr->data == val) { flag = 1;
c1 = count; break;
}
 

else {
ptr = ptr->next;
}
}
if (flag) {
printf("\nElement found at position %d", c1);
} else { printf("\nElement not found");
}
}
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

void counts() { struct node *ptr;
if (head == NULL) { printf("\nList empty!!!");
} else {
int count = 0; ptr = head;
while (ptr != NULL) { count += 1;
ptr = ptr->next;
}
printf("\nThe number of nodes is %d ", count);
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
