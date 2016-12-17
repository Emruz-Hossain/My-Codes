//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
struct st
{
    int x,y;
};
st a;
vector<st>V;
int  n=8,r;
int visit[10][10];

void make_visit(int x,int y,int p)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        visit[x][i]+=p;
        visit[i][y]+=p;
    }
    for(i=x,j=y;i<n&&j<n;i++,j++)
        visit[i][j]+=p;
    for(i=x,j=y;i>=0&&j>=0;i--,j--)
        visit[i][j]+=p;
    for(i=x,j=y;i<n&&j>=0;i++,j--)
        visit[i][j]+=p;

//for(i=0;i<n;i++)
//{
//    for(j=0;j<n;j++)
//    {
//        printf("%d ",visit[i][j]);
//    }
//    printf("\n");
//}
//printf("\n");
}
void queen(int x,int q)
{
    if(x>n)
        return;
    int i,j;
    if(V.size()==n)
    {
        r++;
        for(i=0;i<V.size();i++)
        {
            printf("(%d %d) ",V[i].x+1,V[i].y+1);
        }
        printf("\n");
        //V.clear();
    }
      for(j=0;j<n;j++)
        {
            if(visit[x][j]==0)
            {
                a.x=x;
                a.y=j;
                V.push_back(a);
                make_visit(x,j,1);
                queen(x+1,q+1);
                V.pop_back();
                make_visit(x,j,-1);
            }
        }
}
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int i,j;
        for(j=0;j<n;j++)
        {
            memset(visit,0,sizeof(visit));
            V.clear();
            a.x=0;
            a.y=j;
            V.push_back(a);
            make_visit(0,j,1);
            queen(1,1);
        }
        printf("\n%d\n",r);

    return 0;
}



