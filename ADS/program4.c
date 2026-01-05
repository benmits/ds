#include<stdio.h> #include<stdlib.h>
//menu driven program to sum two numbers using different functions with arguments or without arguments and with return type or without return type
int sum1(int x, int y); void sum2(int x, int y); int sum3();
void sum4();

void main()
{
int a,b,o,sum;
printf("1:With argument and return type\n"); printf("2:With argument and no return type\n"); printf("3:Without argument and return type\n"); printf("4:With argument and no return type\n"); printf("5:Exit\n\n");
printf("Enter the 2 numbers:\n"); scanf("%d%d",&a,&b);
do{
printf("\nEnter an option:"); scanf("%d",&o); switch(o){
case 1: sum=sum1(a,b); printf("Sum is:%d",sum); break;

case 2: sum2(a,b); break;

case 3: sum=sum3(); printf("Sum is:%d",sum); break;

case 4: sum4(); break;
case 5: exit(0); default:printf("Invalid Choice");
break;
}
}
while(o!=5);
 
}
int sum1(int x,int y)
{
return(x+y);
}

void sum2(int x,int y)
{
int s; s=x+y;
printf("Sum is:%d",s);
}

int sum3()
{
int x,y;
printf("Enter the 2 numbers:"); scanf("%d%d",&x,&y); return(x+y);
}
void sum4()
{
int s,x,y;
printf("Enter the 2 numbers:"); scanf("%d%d",&x,&y); s=x+y;
printf("Sum is:%d",s);
}
