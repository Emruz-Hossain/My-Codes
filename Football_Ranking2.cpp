#include<stdio.h>
#include<algorithm>
using namespace std;
struct team_info
{
    int team_id,point,goal_number;
    char team_name[20];
};
team_info ar[20];
int Head_to_head[20][20];
bool cmp(team_info a, team_info b)
{
    if(a.point>b.point)
        return true;
    else if(a.point<b.point)
        return false;
    else
    {
        if(a.goal_number>b.goal_number)
            return true;
        else if(a.goal_number<b.goal_number)
            return false;
        else
        {
            int i=a.team_id;
            int j=b.team_id;
            if(Head_to_head[i][j]==1)
                return true;
            else
                return false;
        }
    }
}
int main()
{
    int i,j,k,n,p,q;
    printf("Enter number of teams in the league:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the name of %d th team: ",i);
        scanf("%s",&ar[i].team_name);
        ar[i].team_id=i;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            printf("Enter the game result between team %d and %d: ",i,j);
            scanf("%d %d",&p,&q);
            if(p>q)
            {
                ar[i].point+=2;
                Head_to_head[i][j]=1;
                Head_to_head[j][i]=0;
            }
            else if(p<q)
            {
                ar[j].point+=2;
                Head_to_head[i][j]=0;
                Head_to_head[j][i]=1;
            }
            else
            {
                ar[i].point+=1;
                ar[j].point+=1;
                Head_to_head[i][j]=-1;
                Head_to_head[j][i]=-1;
            }
            ar[i].goal_number+=p;
            ar[j].goal_number+=q;


        }
    }
    sort(ar,ar+n,cmp);
    printf("\nRanklist:\n");
    printf("Serial    Team_name    Point    Goal_number\n");
    printf("---------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d %18s %6d %7d\n",i,ar[i].team_name,ar[i].point,ar[i].goal_number);
    }
    return 0;
}
