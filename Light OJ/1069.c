#include<stdio.h>
int main()
{
    int t,i,m,l,time;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&m,&l);
        if(m>l)
            time=((m-l)*4)+(4*m+19);
        else
            time=4*l+19;
        printf("Case %d: %d\n",i,time);
    }
    return 0;
}
