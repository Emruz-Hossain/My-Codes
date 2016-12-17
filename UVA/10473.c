#include<stdio.h>
#include<string.h>
#include<math.h>
char str[100];
char store[20];
int l;
void dec2hex(void)
{
    //int i;
    //for(i=l-1;i>1;i++)
}
void hex2dec(void)
{
    int i,result=0,c=0;
    for(i=l-1;i>1;i--)
    {
        result=result+(store[str[i]]*pow(16,c));
        c++;
    }
    printf("%d\n",result);
}
int main()
{
    store[0]='0';store[1]='1';store[2]='2';store[3]='3';store[4]='4';store[5]='5';store[6]='6';store[7]='7';store[8]='8';store[9]='9';
store['A']='10';store['B']='11';store['C']='12';store['D']='13';store['E']='14';store['F']='15';

    int i,n,k;
    while(1)
    {
        n=0;
        k=0;
        scanf("%s",&str);
        if(strcmp(str,"0")==-1)
            break;
        else
        {
            l=strlen(str);
            for(i=0;i<l;i++)
            if(str[1]=='x')
                k=1;
            if(k==1)
                hex2dec();
            else
                dec2hex();

        }
    }
    return 0;
}
