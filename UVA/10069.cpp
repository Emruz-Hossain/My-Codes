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
#include<ctime>
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

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
int ls,lq;
string ss,sq;
map<int,map<int,string> >dp;
string add(string a,string b)
{
    string ans;
    int tmp,carry=0;
    for(int i=a.size()-1,j=b.size()-1; i>=0||j>=0; i--,j--)
    {
        if(i<0) tmp=carry+b[j]-'0';
        else if(j<0) tmp=carry+a[i]-'0';
        else tmp=carry+(a[i]-'0')+(b[j]-'0');

        carry=tmp/10;
        ans+=(tmp%10)+'0';
    }
    if(carry) ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
string rec(int ind,int idx)
{
   string p,q;
    if(idx>=lq)
    {
        return "1";
    }
    else if(ind>=ls)
        return 0;
    if(!dp[idx][ind].empty())
        return dp[idx][ind];
    if(ss[ind]==sq[idx])
        p=rec(ind+1,idx+1);
    q=rec(ind+1,idx);
    return dp[idx][ind]=add(p,q);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    scanf("%d",&t);
    while(t--)
    {
      cin>>ss>>sq;
        ls=ss.size();
        lq=sq.size();
        dp.clear();
        cout<<rec(0,0)<<endl;
    }

    return 0;
}
