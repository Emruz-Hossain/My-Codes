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
    int m,s,e;
}a;
vector<st>E[10000];
int ring,tm;
int visit[100000];
void backtrack(int v)
{
    int s,e,m,i;
    if(visit[v]==1)
    {
        ring=9999;
        return;
    }
    if(ring!=9999)
    {
    ring=v;
    for(i=0;i<E[v].size();i++)
    {
        s=E[v][i].s;
        e=E[v][i].e;
        m=E[v][i].m;
        if(tm>=s&&tm<=e)
        {
            visit[v]=1;
            backtrack(m);
            break;
        }

    }

    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t,x,u,v,j,i,st,et;
    char ss[10],ss2[10];
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        if(x==1)
            printf("CALL FORWARDING OUTPUT\n");
        for(i=0;i<=9999;i++)
            E[i].clear();
        printf("SYSTEM %d\n",x);
        while(1)
        {
        scanf("%d",&u);
        if(u==0)
            break;
        else
            scanf("%d %d %d",&st,&et,&v);
        a.m=v;
        a.s=st;
        a.e=st+et;
        E[u].push_back(a);
        }
        while(1)
        {
            char ss3[10];
            ss3[0]='0';ss3[1]='0';ss3[2]='0';ss3[3]='0';ss3[4]='\0';
            memset(visit,0,sizeof(visit));
            scanf("%s",&ss);
            sscanf(ss,"%d",&tm);
            if(tm==9000)
                break;
            else
            {
                scanf("%s",&ss2);
                sscanf(ss2,"%d",&u);
            }

            ring=u;
            for(i=0;i<E[u].size();i++)
            {
                st=E[u][i].s;
                et=E[u][i].e;
                v=E[u][i].m;
                if(tm>=st&&tm<=et)
                {
                    visit[u]=1;
                    backtrack(v);
                    break;
                }

            }
            int k=3;
            while(ring)
            {
                int d=ring%10;
                ss3[k]=d+48;
                k--;
                ring=ring/10;
            }
            printf("AT %s CALL TO %s RINGS %s\n",ss,ss2,ss3);

        }

        if(x==t)
            printf("END OF OUTPUT\n");
    }

    return 0;
}



