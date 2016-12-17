#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<bits/stdc++.h>
#define N 1000000
using namespace std;

int main()
{
    char num[N],o[N],E[]="ERROR",ss[20];
    int n,m,len,j,t,T,i,sum,power,zero=0,k,flag;
   // freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    while(cin>>num)
    {
        cin>>n>>m;
        sum=0;
        len=strlen(num);
        power=1;
        for(i=0;i<len-1;i++)
          power*=n;
        flag=0;
        for(i=0;i<len;i++)
        {            if(num[i]=='A')
                t=10;
            else if(num[i]=='B')
                t=11;
            else if(num[i]=='C')
                t=12;
            else if(num[i]=='D')
                t=13;
            else if(num[i]=='E')
                t=14;
            else if(num[i]=='F')
                t=15;
            else
                t=(num[i]-'0');
            sum+=t*power;
            power=power/n;
        }
        if(sum==0)
        {
                printf("%7d\n",zero);
                continue;
        }
        i=0;
        if(m<=10)
        {
            while(sum!=0)
            {
                T=sum%m;
                sum/=m;
                o[i]=T+'0';
                i++;
            }
            if(i<8)
            {
                for(j=i-1,k=0;j>=0;j--,k++)
                    ss[k]=o[j];
                ss[k]='\0';
                printf("%7s",ss);
            }
            else
               printf("%7s",E);
        }
        else
        {
            while(sum!=0)
            {
                T=sum%m;
                sum/=m;
                if(T==10)
                    o[i]='A';
                else if(T==11)
                    o[i]='B';
                else if(T==12)
                    o[i]='C';
                else if(T==13)
                    o[i]='D';
                else if(T==14)
                    o[i]='E';
                else if(T==15)
                    o[i]='F';
                else
                    o[i]=T+'0';
                i++;
            }
            if(i<8)
            {
                for(j=i-1,k=0;j>=0;j--,k++)
                    ss[k]=o[j];
                ss[k]='\0';
                printf("%7s",ss);
            }
            else
            printf("%7s",E);
        }
   printf("\n");
    }

return 0;
}
