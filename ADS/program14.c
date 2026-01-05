#include <stdio.h> #include <stdlib.h> struct Node
{
int data;
struct Node *next;
};
struct Node *top = NULL; void push();
void pop(); void traversal(); int main()
{
int ch; printf("1.push\n2.pop\n3.traversal\n4.exit"); while(1)
{
printf(“\nEnter your choice:”); scanf("%d", &ch);
switch(ch)
{
case 1: push(); break; case 2: pop(); break; case 3: traversal(); break; case 4: exit(0);
default: printf("Invalid\n");
}
 

}
return 0;
}
void push()
{
int value;
struct Node *newNode; printf("Enter the value to insert: "); scanf("%d", &value);
newNode = (struct Node*)malloc(sizeof(struct Node)); if(newNode == NULL)
{
printf("Memory not allocated\n"); return;
}
newNode->data = value; newNode->next = top; top = newNode;
printf("Pushed %d\n", value);
}
void pop()
{
struct Node *temp; if(top == NULL)
{
printf("Stack Underflow\n"); return;
}
temp = top;
printf("Popped %d\n", top->data); top = top->next;
free(temp);
}


void traversal()
{
struct Node *temp; if(top == NULL)
{ printf("Stack empty\n"); return;
}
 

printf("Stack elements are: "); temp = top;
while(temp != NULL)
{
printf("%d ", temp->data); temp = temp->next;
}
printf("\n");
}
