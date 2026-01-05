#include <stdio.h> #include <stdlib.h> void enqueue(int size); void dequeue();
void traversal();
int a[20], front = -1, rear = -1; void main(){
int n, ch;
printf("Enter the limit : "); scanf("%d", &n);
printf("1.Enqueue \n2.Dequeue \n3.Traversal \n4.Exit ");
do
{
printf(\nEnter your Choice:); scanf("%d", &ch);
switch (ch)
{
case 1:
enqueue(n); break;
case 2:
dequeue(); break;
case 3:
traversal(); break;
case 4:
exit(0);
 

default:
printf("Enter a valid option!! ");
}
} while (ch != 4);
}
void enqueue(int size)
{
int item;
if (rear == size - 1)
{
printf("Queue size is full!\n"); return;
}
printf("Enter the element to insert :\n"); scanf("%d", &item);
if (front == -1 && rear == -1)
{
front = rear = 0;
}
else
{
rear = rear + 1;
}
a[rear] = item;
}


void dequeue()
{
if (front == -1 && rear == -1)
{
printf("Queue is empty\n");
}
else
{
int item;
item = a[front]; if (front == rear)
{
front = rear = -1;
}
 
else
{
front = front + 1;

}
printf("ITEM REMOVED :\n");
}}

void traversal()
{
if (rear < 0)
{
printf("Queue underflow!\n");
}
else
{
int i;
for (i = front; i <= rear; i++)
{
printf("%d\t", a[i]);
}
printf("\n");
}
}
