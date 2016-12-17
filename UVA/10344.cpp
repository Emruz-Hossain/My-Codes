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
vector<int>E,V,OR[100];
int l,visit[30],k,w=0;
int ss[10];
int  cal(int x,int y,int p)
{
    if(p==1)
        return x+y;
    if(p==2)
        return x-y;
    if(p==3)
        return x*y;
}
void operation(vector<int>num)
{
    int ans,i;
    for(i=0;i<w;i++)
    {
            ans=num[0];
            ans=cal(ans,num[1],OR[i][0]);
            ans=cal(ans,num[2],OR[i][1]);
            ans=cal(ans,num[3],OR[i][2]);
            ans=cal(ans,num[4],OR[i][3]);
            ans=cal(ans,num[5],OR[i][4]);
            if(ans==23)
            {
                k=1;
                break;
            }
    }

}
void calculate()
{
    int i;
    if(V.size()==4)
    {
       for(i=0;i<4;i++)
        OR[w].push_back(V[i]);
            w++;
        return;
    }
    for(i=1;i<=3;i++)
        {
            V.push_back(i);
            calculate();
            V.pop_back();
        }
}
void backtrack(void)
{
    int i;
    if(k==1)
        return;
    if(E.size()==l)
    {
       operation(E);
    }
    for(i=0;i<l;i++)
    {
        if(visit[i]==0)
        {
            E.push_back(ss[i]);
            visit[i]=1;
            backtrack();
            E.pop_back();
            visit[i]=0;
        }
    }
}
int main()
{
        //freopen("output.txt","w",stdout);
        //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    l=5;
    w=0;
    calculate();
    while(1)
    {
    E.clear();
    V.clear();
    scanf("%d %d %d %d %d",&ss[0],&ss[1],&ss[2],&ss[3],&ss[4]);
    if(ss[0]==0&&ss[1]==0&&ss[2]==0&&ss[3]==0&&ss[4]==0)
        break;
    memset(visit,0,sizeof(visit));
    k=0;
   backtrack();
    if(k==1)
        printf("Possible\n");
    else
        printf("Impossible\n");
    }
    return 0;
}
