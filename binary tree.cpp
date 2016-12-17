#include<stdio.h>
#include<string.h>
int ar[100000];
int max=0;
void set(int p,int m)
{
    if(m<=ar[p])
    {
        if(ar[2*p]==0)
            {
                ar[2*p]=m;
                if(max<2*p)
                    max=2*p;
            }
        else
            set(2*p,m);
    }
    else
    {
        if(ar[2*p+1]==0)
            {
                 ar[2*p+1]=m;
                if(max<2*p+1)
                    max=2*p+1;
            }

        else
            set(2*p+1,m);
    }


}
int main()
{
    int n,i,p,m;
    while(scanf("%d",&n)==1)
    {
    memset(ar,0,sizeof(ar));
    max=0;
    scanf("%d",&ar[1]);
    for(i=1;i<n;i++)
    {
        scanf("%d",&m);
        set(1,m);
    }
    for(i=0;i<=max;i++)
        if(ar[i]!=0)
        printf("%d ",ar[i]);
    }
    return 0;
}
