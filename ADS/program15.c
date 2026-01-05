#include <stdio.h> #include <stdlib.h> struct Node {
int data;
struct Node* next;
};
struct Node* front = NULL; struct Node* rear = NULL; void enqueue() {
int item;
printf("Enter the element to insert:\n"); scanf("%d", &item);
struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); if (temp == NULL) {
printf("Memory allocation failed\n"); return;
}
 

temp->data = item; temp->next = NULL; if (rear == NULL) {
front = rear = temp;
} else {
rear->next = temp; rear = temp;
}
}

void dequeue() {
if (front == NULL) { printf("Queue is empty\n"); return;
}
struct Node* temp = front;
printf("ITEM REMOVED : %d\n", temp->data); front = front->next;
if (front == NULL) { rear = NULL;
}
free(temp);
}

void traversal() {
if (front == NULL) { printf("Queue is empty!\n"); return;
}
struct Node* temp = front; printf("Queue elements: ");
while (temp != NULL) { printf("%d\t", temp->data); temp = temp->next;
}
printf("\n");
}
 

int main() { int ch;
printf("1.Enqueue \n2.Dequeue \n3.Traversal \n4.Exit "); do {
printf(“\nEnter your Choice:”);
scanf("%d", &ch); switch(ch) {
case 1:
enqueue(); break;
case 2:
dequeue(); break;
case 3:
traversal(); break;
case 4:
break; default:
printf("Enter a valid option!! \n");
}
} while (ch != 4); return 0;
}

