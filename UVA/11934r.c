#include<stdio.h>
int main()
{
    int a,b,c,d,l,f,i,m;
    while(1)
    {
        m=0;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&l);
        if(a==0&&b==0&&c==0&&d==0&&l==0)
            break;
        else
        {
            for(i=0;i<=l;i++)
            {
                f=(a*i*i)+(b*i)+c;
                if(f%d==0)
                    m++;
            }
            printf("%d\n",m);
        }
    }
    return 0;

}
