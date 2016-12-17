#include<stdio.h>
#include<math.h>
int main()
{
    int i,t,m,n,r,c,d;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&r,&c);
        m=r/2;
        n=c/2;
        if(r==1)
            d=c;
        else if(c%2==0)
          d=n*r;
        else
        {
            if(r%2==0)
                d=(n+1)*m+(n*m);
            else
                d=(n+1)*(m+1)+m*n;

        }
        printf("Case %d: %d\n",i,d);
    }
    return 0;
}
