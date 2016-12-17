#include<stdio.h>
int main()
{
    int roads,number,i,t=0;
    while(1)
    {
        t++;
        scanf("%d %d",&roads,&number);
        if(roads==0&&number==0)
            break;
        else
        {
            if((number+26*number)<roads)
                printf("Case %d: impossible\n",t);
            else if(roads<number)
                printf("Case %d: 0\n",t);
            else
            {
                for(i=1;i<=26;i++)
                {
                    if((number+i*number)>=roads)
                        break;
                }
                printf("Case %d: %d\n",t,i);
            }
        }
    }
    return 0;
}
