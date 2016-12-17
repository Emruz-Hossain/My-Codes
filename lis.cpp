#include<stdio.h>
#include<string.h>
int ar[100],lis[100],i,n,p[100],j,max=0,pm;
void liseq(int u)
{
    if(u==-1)
        return;
    liseq(p[u]);
    printf("%d ",ar[u]);
}
int main()
{

    memset(lis,0,sizeof(lis));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
        if(i==0)
        {
            lis[i]=1;
            p[i]=-1;
        }
        else
        for(j=0;j<i;j++)
        {
            if(ar[i]>ar[j])
            {
                if(lis[j]>=lis[i])
                {
                    lis[i]=lis[j]+1;
                    p[i]=j;
                }
            }
        }
        if(max<lis[i])
        {
             max=lis[i];
             pm=i;
        }

    }
    printf("\nLength of longest subsequence: %d\n\nSequence is:\n",max);
    liseq(pm);
    printf("\n");
    return 0;
}

