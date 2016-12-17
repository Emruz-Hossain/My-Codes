#include<stdio.h>
int main()
{
    int t,i,n,j,pm,q,ml,jc,d;
    scanf("%d",&t);
    for(j=1;j<=t;j++)
    {
        ml=0;jc=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&d);
            pm=d/30;
            q=d/60;
            if(pm*29>=d)
            {
                ml+=10*pm;
            }
            else
                ml+=10*(pm+1);
            if(q*59>=d)
            {
                jc+=q*15;
            }
            else
                jc+=(q+1)*15;
        }
        if(ml==jc)
            printf("Case %d: Mile Juice %d\n",j,ml);
        else if(ml<jc)
            printf("Case %d: Mile %d\n",j,ml);
        else
            printf("Case %d: Juice %d\n",j,jc);

    }
    return 0;
}
