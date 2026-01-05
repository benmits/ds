#include<stdio.h>
//sort an integer array void main()
{
int a[10],n,temp; printf("Enter a limit:"); scanf("%d",&n); printf("\nEnter an array:\n"); for(int i=0;i<n;i++) scanf("%d",&a[i]);

printf("\nOriginal array is:\n"); for(int i=0;i<n;i++) printf("%d",a[i]);
for(int i=0;i<n;i++)
{
 
for(int j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j+1]; a[j+1]=a[j]; a[j]=temp;
}
}
}
printf("\nSorted array is:\n"); for(int i=0;i<n;i++) printf("%d",a[i]);
}
