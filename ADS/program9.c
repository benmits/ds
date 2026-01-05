#include<stdlib.h> #include<stdio.h> #define SIZE 5 void push(int value); void pop();
void display(); int stack[SIZE]; int top = -1;
int main{
int choice, value;
printf("Stack operations: \n1. Push \n2. Pop \n3. Display \n4. Exit \n"); do
{
printf(“Enter your choice:”) scanf("%d", &choice); switch(choice)
{
case 1:
printf("Enter value to push: "); scanf("%d", &value); push(value);
break; case 2:
pop(); break;
case 3:
display(); break;
case 4:
exit(0); break;
default:
printf("Invalid choice\n"); break;
}
 

} while (choice != 4); return 0;
}
void push(int value)
{
if (top == SIZE - 1)
{
printf("Stack overflow\n");
}
else
{
top++;
stack[top] = value;
printf("%d pushed into stack\n", value);
}
}
void pop()
{
if (top == -1)
{
printf("stack underflow\n");
}
else
{
printf("%d popped from stack\n", stack[top]); top--;
}
}

void display()
{
if (top == -1)
{
printf("Stack is empty\n");
}
else
{
printf("Stack elements are:\n"); for (int i = top; i >= 0; i--)
{
printf("%d\n", stack[i]);
}
}
}
