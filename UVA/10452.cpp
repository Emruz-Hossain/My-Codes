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
char str[]={'@','I','E','H','O','V','A','#'};
vector<string> E;
char ss[10][10];
int m,n;
void backtrack(int x,int y,int ind)
{
    int i,l;
    if(ind>8)
        return;
    if(ind==8)
    {
         l=E.size();
        for(i=0;i<l;i++)
        {
            cout<<E[i];
            if(i<l-1)
                cout<<" ";
        }
        cout<<endl;
    }
    if(ss[x-1][y]==str[ind]&&x>=0)
    {
        E.push_back("forth");
        backtrack(x-1,y,ind+1);
        E.pop_back();
    }
    if(ss[x][y-1]==str[ind]&&y>=0)
    {
        E.push_back("left");
        backtrack(x,y-1,ind+1);
        E.pop_back();
    }
    if(ss[x][y+1]==str[ind]&&y<n)
    {
        E.push_back("right");
        backtrack(x,y+1,ind+1);
        E.pop_back();
    }

}
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        E.clear();
         scanf("%d %d",&m,&n);
         for(i=0;i<m;i++)
            scanf("%s",&ss[i]);
         for(i=0;i<m;i++)
         {
             for(j=0;j<n;j++)
             {
                 if(ss[i][j]=='@')
                 {
                     backtrack(i,j,1);
                 }
             }
         }
    }

    return 0;
}

