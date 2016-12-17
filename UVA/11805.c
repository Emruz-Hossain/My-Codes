#include<stdio.h>
int main()
{
    int Test_case,Number,player_no,Pass,i,R,j;
    scanf("%d",&Test_case);
    for(i=1;i<=Test_case;i++)
    {
        scanf("%d %d %d",&Number,&player_no,&Pass);
        R=player_no;
        if(R>Number)
            R=player_no-Number;
        for(j=1;j<=Pass;j++)
        {
            if(R>=Number)
                R=1;
            else
                R=R+1;
        }
        printf("Case %d: %d\n",i,R);
    }
    return 0;
}
