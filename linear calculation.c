#include<stdio.h>
#include<string.h>
void division(int m);
char input[100];
int i;
int main()
{

    int length;
    gets(input);
    length=strlen(input);
    for(i=0;i<length;i++)
    {
        if(input[i]=='/')
            //printf("%d",input[i-1]-48);
            division(input[i-1]-48);
    }
    return 0;

}
void division(int m)
{
    int result;
    result=m/(input[i+1]-48);
    printf("%d",result);
}
