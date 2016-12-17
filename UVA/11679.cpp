#include<stdio.h>
#include<string.h>
int main()
{
    int ar[100],b,n,i,p,q,v,x;
    while(1)
    {
        memset(ar,0,sizeof(ar));
    scanf("%d %d",&b,&n);
    if(b==0&&n==0)
        break;
    for(i=1;i<=b;i++)
        scanf("%d",&ar[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&p,&q,&v);
        ar[p]-=v;
        ar[q]+=v;
    }
    x=1;
    for(i=1;i<=b;i++)
        {
            if(ar[i]<0)
                {
                    x=0;
                    break;
                }
        }
    if(x==1)
        printf("S\n");
    else
        printf("N\n");

}
return 0;

}
