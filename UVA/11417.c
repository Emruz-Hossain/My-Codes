#include<stdio.h>
int GCD(int m,int n)
{
    if(n%m==0)
        return m;
    else
        GCD(n%m,m);
}
int main()
{
    int i,j,N,G;
    while(1)
    {
        G=0;
        scanf("%d",&N);
        if(N==0)
            break;
        for(i=1;i<N;i++)
            for(j=i+1;j<=N;j++)
            G+=GCD(i,j);
        printf("%d\n",G);
    }
    return 0;

}
