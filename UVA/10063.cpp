
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
char str[15];
vector<char>V;
int l;
void backtrack(int ind)
{
    char tmp;
    int i,j;
    if(V.size()==l)
    {
        for(i=0;i<l;i++)
            printf("%c",V[i]);
        printf("\n");
    }
    V.push_back('*');
    for(i=0;i<V.size();i++)
    {
        for(j=V.size()-1;j>i;j--)
        {
            V[j]=V[j-1];
        }
        V[i]=str[ind];
        backtrack(ind+1);
        V.pop_back();
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    scanf("%s",&str);
    l=strlen(str);
    V.push_back(str[0]);
    backtrack(0);

    return 0;
}
