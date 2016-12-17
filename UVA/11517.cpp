#include<stdio.h>
#include<string.h>
int paid=1<<25,used,dif;
int coin[200];
void rec(int p,int n,int amount,int indx,int x)
{
    int i,total,diff;
    if(amount>p)
        return;
    else
    {   x++;
        for(i=indx;i<n;i++)
        {
            total=amount+coin[i];
            if(total>=p)
            {
                diff=total-p;
                if(diff<paid-p)
                {
                    paid=total;
                    used=x;
                }
            }
            rec(p,n,total,i+1,x);
        }
    }

}
int main()
{
    int t,i,j,n,p;
    scanf("%d",&t);
    while(t--)
    {
        paid=1<<25;
        dif=1<<24;
        memset(coin,0,sizeof(coin));
        scanf("%d",&p);
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&coin[i]);
        rec(p,n,0,0,0);
        printf("%d %d\n",paid,used);
    }
    return 0;
}
