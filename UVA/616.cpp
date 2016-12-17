#include<stdio.h>
#include<math.h>
int main()
{
    int coconuts,m,i,k,j;
    while(1)
    {
        scanf("%d",&coconuts);
        if(coconuts<0)
            break;
        else
        {
            if(coconuts==0)
                    printf("%d coconuts, no solution\n",coconuts);
            else
            {
                if(m>=9)
                m=sqrt(coconuts);
                else
                    m=coconuts;
                for(i=m;i>0;i--)
                {
                    k=coconuts;
                       for(j=1;j<=i;j++)
                       {
                           if(k%i!=1)
                            break;
                           k=k-((k/i)+1);
                       }
                        if(j==i+1&&k%i==0)
                            break;
                }
            if(i==0)
                printf("%d coconuts, no solution\n",coconuts);
            else
                printf("%d coconuts, %d people and 1 monkey\n",coconuts,i);
            }
        }
    }
    return 0;
}
