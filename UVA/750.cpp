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
#include<iomanip>
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
vector<string> E;
vector<st>V;
int  n=8,r,xx,yy;
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
    for(i=x,j=y;i>=0&&j<n;i--,j++)
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
    if(V.size()==n&&x!=xx)
    {
        string ss;
        for(i=0;i<8;i++)
        {
            ss+='0';
            if(i<7)
                ss+=' ';
        }
        for(i=0;i<8;i++)
        {
            ss[2*V[i].y]=V[i].x+48+1;
        }
        E.push_back(ss);
    }
    if(x==xx)
        queen(x+1,q);
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
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
            scanf("%d %d",&xx,&yy);
            memset(visit,0,sizeof(visit));
            V.clear();
            E.clear();
            xx--;
            yy--;
            a.x=xx;
            a.y=yy;
            V.push_back(a);
            make_visit(xx,yy,1);
            queen(0,1);
            sort(E.begin(),E.end());
            cout<<"SOLN       COLUMN\n";
            cout<<" #      1 2 3 4 5 6 7 8\n\n";
            for(i=0;i<E.size();i++)
            {
                cout<<setw(2)<<right<<i+1<<"      "<<E[i]<<endl;
            }
            if(t>0)
               cout<<endl;
    }

    return 0;
}
