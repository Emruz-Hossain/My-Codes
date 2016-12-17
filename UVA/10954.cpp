#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int aray[5050],n,total_cost,i,sum1=0,sum2,total1,total2,sum;
    while(1)
    {
        sum=0;
        total_cost=0;total1=0;total2=0;sum1=0;sum2=0;
        scanf("%d",&n);
        if(n==0)
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&aray[i]);
            }

        }
        printf("%d\n",total_cost);
    }
    return 0;
}
