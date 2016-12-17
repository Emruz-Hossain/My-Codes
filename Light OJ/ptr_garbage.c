#include<stdio.h>
#include<conio.h>
int main()
{
    int *ptr=100000,x=16;
    printf("%x\t%x\n",ptr,*ptr);
    ptr=&x;
    printf("%x\t%x",ptr,*ptr);
    return 0;
}
