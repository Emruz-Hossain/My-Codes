#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i,k,c=0;
    while(1)
    {
        k=0;

        scanf("%d %d",&m,&n);
        if(m==0&&n==0)
            break;
        else
        for(i=m;i<=n;i++)
        {
            if(i==(sqrt(i)*sqrt(i)))
                k++;
        }
        printf("%d\n",k);
        c++;
        if(c==201)
            break;
    }
    return 0;
}
