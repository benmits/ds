#include<stdio.h> #include<stdlib.h>
//menu driven program to do array operations void insertion(int *x, int *y)
{
int j=*y-1,k,item;
printf("Enter the element to be inserted:\n"); scanf("%d",&item);
printf("Enter the position to be inserted:\n"); scanf("%d",&k);
while(j>=k)
{
x[j+1]=x[j]; j=j-1;
}
x[k]=item;
*y=*y+1;
printf("Inserted and size is:%d",*y);
}
 
void deletion(int *x,int *y)
{
int k,item;
printf("Enter the position to be deleted:\n"); scanf("%d",&k);
item=x[k];
for(int i=k;i<*y-1;i++) x[i]=x[i+1];
*y=*y-1;
printf("Deleted and size is:%d",*y);
}
void traverse(int *x,int *y){ printf("Array is\n");
for(int i=0;i<*y;i++)
{
printf("%d",x[i]);
}
}
void main()
{
int a[10],n,o; printf("1:Insertion\n"); printf("2:Deletion\n"); printf("3:Traverse\n"); printf("4:Exit\n\n"); printf("Enter the limit:\n"); scanf("%d",&n); printf("Enter the array:\n"); for(int i=0;i<n;i++) scanf("%d",&a[i]);
do{
printf("\nEnter an option:"); scanf("%d",&o); switch(o){
case 1: insertion(a,&n); break;
case 2: deletion(a,&n); break;
case 3: traverse(a,&n); break;
case 4: exit(0); default:
printf("Invalid Choice"); break;
}
 
}
while(o!=4);
}
