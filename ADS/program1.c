#include<stdio.h> void main(){
int a,b;
printf("enter value of a and b\n");
 
scanf("%d%d",&a,&b);
printf("result %d",(a+b));
}

// myfile.c 
#include <stdio.h> 
void main()
{
#ifdef SAMPLE
printf("With preprocessor directive= %d\n",SAMPLE);
 
#else


#endif
}

// myheader.h 
#define NUM1 5
// myfile.c 
#include <stdio.h>
#include "myheader.h"

void main()
{
int num = NUM1; printf("num=%d\n", num);
}


