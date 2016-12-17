#include<stdio.h>
int main()
{
    int t,v,s;
    while(scanf("%d %d",&v,&t)!=EOF)
    {
        if((v>=-100&&v<=100)&&(t>=0&&t<=200))
        {
            t=t*2;
            s=v*t;
        }
        printf("%d\n",s);
    }
    return 0;
}
