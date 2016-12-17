//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}
 map<string,string>parent,new_name;
string old,newh;
vector<string>v,usin;
map<string,int>visit,visit2;
struct st
{
    vector<string>used;
};
map<st>mp;
string fparent(string ss)
{
    string sp=parent[ss];
   // cout<<"sp="<<sp<<endl;
    if(sp.size()==0)
    {
        return ss;
    }
    else
        return fparent(parent[ss]);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
    int a,b,c,d,h,m,n,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
    parent.clear();
    sf("%d",&q);
    while(q--)
    {
        cin>>old>>newh;
        if(old==newh)
            continue;
        string p=fparent(old);
        if(p==old)
        {
            d=1;
            for(i=0;i<usin.size();i++)
            {
                if(usin[i]==newh&&cur[newh]==1)
                {
                    d=0;
                    break;
                }
            }
            for()
            parent[newh]=old;
            if(visit2[old]==0)
            {
                 v.push_back(old);
                 visit2[old]=1;
            }

            new_name[old]=newh;
        }
        else if(visit[newh]==0)
        {
            new_name[p]=newh;
        }
        visit[newh]=1;
        //cout<<"parent["<<newh<<"]="<<parent[newh]<<endl;
    }
    pf("%d\n",v.size());
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" "<<new_name[v[i]]<<endl;
        }
    return 0;
}
