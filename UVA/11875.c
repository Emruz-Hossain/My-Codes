#include<stdio.h>
int main()
{
    int store[21],no_player,i,test_case,j;
    scanf("%d",&test_case);
    for(i=1;i<=test_case;i++)
    {
        scanf("%d",&no_player);
        for(j=0;j<no_player;j++)
            scanf("%d",&store[j]);
        printf("Case %d: %d\n",i,store[(no_player/2)]);
    }
    return 0;
}
