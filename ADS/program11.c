#include<stdio.h> #include<stdlib.h> void enqueue(); void dequeue(); void display();
int a[20], front = 0, rear = 0, count = 0, size;
int main()
{
int ch; printf("Enter the
limit(max 20): "); scanf("%d", &size); if (size <= 0 || size > 20) {
printf("Invalid sizeentered. Defaulting to 10.\n"); size = 10;
}
printf("\n1. Enqueue \n2. Dequeue \n3.Display\n4. Exit") do {
printf(“\nEnter your Choice:”); scanf("%d", &ch);
switch (ch) {
 

case 1:
enqueue(); break; case 2:
dequeue(); break; case 3:
display(); break; case 4:
exit(0); default:
printf("Enter a valid option!! \n");
}
} while (ch != 4); return 0;
}
void enqueue() { int item;
if (count == size) { printf("Queue size is full!\n");
} else {
printf("Enter the element to insert: "); scanf("%d", &item); a[rear] = item;
rear = (rear + 1) % size;

count = count + 1; printf("Inserted %d\n", item);
}}
void dequeue() { if (count == 0) {
printf("Queue is empty\n");
} else { int item;
item = a[front];
front = (front + 1) % size; count = count - 1; printf("ITEM REMOVED: %d\n", item);
}
}
void display() {
if (count == 0) { printf("Queue is empty!\n");
}
else {
printf("Queue elements: "); int i;
int current_index =front; for (i = 0; i < count; i++)
{
printf("%d ", a[current_index]); current_index = (current_index + 1) % size;
}
printf("\n");
}
}