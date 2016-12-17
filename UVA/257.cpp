//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,l,cnt,sm;
    char ch1,ch2;
    char ss[257];
    while(scanf("%s",&ss)==1)
    {
        l=strlen(ss);
        cnt=0;
        for(i=1;i<l-1;i++)
        {
            if(ss[i-1]==ss[i+1])
            {
                sm=3;
                ch1=ss[i-1];
                ch2=ss[i];
                cnt=1;
                break;
            }
            else if(ss[i]==ss[i+1]&&ss[i-1]==ss[i+2])
            {
                sm=4;
                ch1=ss[i-1];
                ch2=ss[i];
                cnt=1;
                break;
            }
        }
        if(cnt==1){
        for(j=i+1;j<l-1;j++)
        {
            if(ss[j-1]==ss[j+1])
            {
                if(sm==4||(ch1!=ss[j-1]||ch2!=ss[j]))
                {
                   printf("%s\n",ss);
                    break;
                }
            }
            else if(ss[j]==ss[j+1]&&ss[j-1]==ss[j+2])
            {
                if(sm==3||(ch1!=ss[j-1]||ch2!=ss[j]))
                {
                   printf("%s\n",ss);
                    break;
                }
            }
        }}
    }
    return 0;
}

