#include<stdio.h>
#include<string.h>

int ar[1000],P[1000],lis[1000];

void path(int p)
{
    if(P[p]==-1)
    {
        printf("%d",ar[p]);
        return;
    }
    path(P[p]);
    printf(" %d",ar[p]);

}

int LIS(int n)
{
    int md,h,l,i,j,k;
    for(i=0,j=0;i<n;i++)
    {
        if(i==0)
        {
            lis[j]=i;
            j++;
        }
        else
        {
            l=0;h=j-1;
            md=(l+h)/2;
            while(l<=h)
            {
                if(ar[lis[md]]<ar[i])
                {
                    if(md!=j-1&&ar[lis[md+1]]<ar[i])
                        l=md+1;
                    else
                        break;
                }
                else
                {
                    h=md-1;
                }
                md=(l+h)/2;
            }
            if(l>h)
            {
                lis[0]=i;
            }
            else
            {
                lis[md+1]=i;
                P[i]=lis[md];
                if(md+1==j)
                    j++;
            }
        }
    }
    return j;
}

int main()
{
    int a,b,i,j,n,m;
    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        memset(P,-1,sizeof(P));
        m=LIS(n);
        printf("%d\n",m);
        path(lis[m-1]);
        printf("\n");
    }
}
