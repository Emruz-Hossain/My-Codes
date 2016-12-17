#include<stdio.h>
int aray[1000050];
int finder(int m,int n)
{
    int low=0,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(m==aray[mid])
            return mid;
        if(m<aray[mid])
            {
                if((mid-1)>=0&&m>=aray[mid-1])
                    return mid-1;
                else
                    high=mid-1;
            }
        if(m>aray[mid])
        {
            low=mid+1;
        }

    }
    if(low>n)
        return n;
    if(high<0)
        return 0;
    }

int main()
{
    int t,n,s,i,x,l,h,c,seg[50050][2],j;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        scanf("%d %d",&n,&s);
        for(i=0;i<n;i++)
            scanf("%d",&aray[i]);
        for(i=0;i<s;i++)
        {
            for(j=0;j<2;j++)
                scanf("%d",&seg[i][j]);
        }
        printf("Case %d:\n",x);
        for(i=0;i<s;i++)
        {
            c=0;
            l=finder(seg[i][0],n-1);
            h=finder(seg[i][1],n-1);
            if(l==h&&aray[l]>=seg[i][0]&&aray[l]<=seg[i][1])
                c=1;
             else if(l!=h&&aray[l]>=seg[i][0]&&aray[h]<=seg[i][1])
                c=h-l+1;
            else
                c=h-l;
            printf("%d\n",c);
        }
        }


    return 0;
}


