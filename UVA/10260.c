#include<stdio.h>
#include<string.h>
int main()
{
    char str[250],arr[250]={0};
    int i,l;
    arr['B']=1;arr['F']=1;arr['P']=1;arr['V']=1;arr['C']=2;arr['G']=2;
    arr['J']=2;arr['K']=2;arr['Q']=2;arr['S']=2;arr['X']=2;arr['Z']=2;
    arr['D']=3;arr['T']=3;arr['L']=4;arr['M']=5;arr['N']=5;arr['R']=6;
    while(scanf("%s",str)==1)
    {
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(arr[str[i]]>=1&&arr[str[i]]<=6&&i==0)
                printf("%d",arr[str[i]]);
            else if(arr[str[i]]>=1&&arr[str[i]]<=6&&arr[str[i]]!=arr[str[i-1]])
                printf("%d",arr[str[i]]);
        }
        printf("\n");
    }
    return 0;
}
