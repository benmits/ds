#include<stdio.h> #include<stdlib.h>
//linear search and binary search of an array using menudriven void ls(int x[],int y);
void bs(int x[],int y);

void main()
{
int a[10],n,o; printf("Enter a limit:"); scanf("%d",&n);
printf("\nEnter an array:\n"); for(int i=0;i<n;i++) scanf("%d",&a[i]); printf("\n1:Linear search\n"); printf("\n2:Binary search\n"); printf("\n3:Exit\n");
 
do{
printf("\nEnter an option:\n"); scanf("%d",&o);
switch(o)
{
case 1:ls(a,n); break;
case 2:bs(a,n); break;
case 3:exit(0); default:printf("invalid choice");
}
}
while(o!=3);
}

void ls(int x[],int y)
{
int item,f=0,i; printf("Enter an item:\n"); scanf("%d",&item); for(i=0;i<y;i++)
{
if(x[i]==item)
{
f=1;
break;
}
}
if(f==1)
printf("%d is found out at position %d\n",item,i); else
printf("Not Found");
}
void bs(int x[],int y)
{
int mid,high=y-1,low=0,temp,item,i,f=0; printf("Enter an item:\n"); scanf("%d",&item);
for(i=0;i<y;i++)
{
for(int j=0;j<y-i-1;j++)
{
if(x[j]>x[j+1])
{
temp=x[j+1];
 
x[j+1]=x[j]; x[j]=temp;
}
}
}
while(low<=high){ mid=(high+low)/2; if(x[mid]==item)
{f=1;
printf("%d is found at position %d",item,mid); break;
}
else if(x[mid]>item) high=mid-1;

else low=mid+1;
}
if (f==0) printf("Not found");
}
