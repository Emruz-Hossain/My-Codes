#include<stdio.h>
#include<string.h>
int leap(int n)
{
    if(n%400==0)
        return 1;
    else if(n%4==0&&n%100!=0)
        return 1;
    else
        return 0;
}
int month(char m[])
{
    if(strcmp(m,"January")==0)
        return 1;
    if(strcmp(m,"February")==0)
        return 2;
    if(strcmp(m,"March")==0)
        return 3;
    if(strcmp(m,"April")==0)
        return 4;
    if(strcmp(m,"May")==0)
        return 5;
    if(strcmp(m,"June")==0)
        return 6;
    if(strcmp(m,"July")==0)
        return 7;
    if(strcmp(m,"August")==0)
        return 8;
    if(strcmp(m,"September")==0)
        return 9;
    if(strcmp(m,"Octobar")==0)
        return 10;
    if(strcmp(m,"Nobember")==0)
        return 11;
    if(strcmp(m,"December")==0)
        return 12;
}
int main()
{
    int d1,d2,y1,y2,t,i,m1,m2,l,s,e,r,j,dif;
    char a1[30],a2[30];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        l=0;
        scanf("%s %d, %d",&a1,&d1,&y1);
        scanf("%s %d, %d",&a2,&d2,&y2);
        m1=month(a1);
        m2=month(a2);
        if(m1<=2)
            s=y1;
        else
            s=y1+1;
        if(s%2!=0)
            s+=1;
        if(m2>=2)
            e=y2;
        else
            e=y2-1;
        dif=e-s;
        /*if(dif>10000)
        {
            for(j=s;j<=e;j+=10000)
            {
                if(j>e)
                    break;
                l+=2425;
            }
            s=j-10000;
        }*/
        for(j=s;j<=e;j+=1)
        {
            r=leap(j);
            if(r==1)
                l++;
        }
        printf("Case %d: %d\n",i,l);
    }
    return 0;
}
