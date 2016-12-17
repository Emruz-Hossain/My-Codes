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
//#include<bits/stdc++.h>
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

vector<int>A,B,C;
int mov,mv;
void solve(int disk,int From,int Help,int To)
{
    int i,p;
    if(mv<mov)
    {
    if(disk==1&&mv<mov)
    {
        if(From==1)
        {
            p=A.back();
            A.pop_back();
        }
        else if(From==2)
        {
            p=B.back();
            B.pop_back();
        }
        else
        {
            p=C.back();
            C.pop_back();
        }
        if(To==1)
        {
            A.push_back(p);
        }
        else if(To==2)
        {
            B.push_back(p);
        }
        else
        {
            C.push_back(p);
        }
        pf("\n");
        pf("A=>");
        for(i=0;i<A.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",A[i]);
        }
        pf("\nB=>");
        for(i=0;i<B.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",B[i]);
        }
        pf("\nC=>");
        for(i=0;i<C.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",C[i]);
        }
        pf("\n");
        ++mv;
    return;
    }
    else if(mv<mov)
    {
        solve(disk-1,From,To,Help);
        if(mv==mov)
            return;
        if(From==1)
        {
            p=A.back();
            A.pop_back();
        }
        else if(From==2)
        {
            p=B.back();
            B.pop_back();
        }
        else
        {
            p=C.back();
            C.pop_back();
        }
        if(To==1)
        {
            A.push_back(p);
        }
        else if(To==2)
        {
            B.push_back(p);
        }
        else
        {
            C.push_back(p);
        }
        pf("\n");
        pf("A=>");
        for(i=0;i<A.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",A[i]);
        }
        pf("\nB=>");
        for(i=0;i<B.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",B[i]);
        }
        pf("\nC=>");
        for(i=0;i<C.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",C[i]);
        }
        pf("\n");
        ++mv;
        if(mv==mov)
            return;
        solve(disk-1,Help,From,To);
    }
    }
}
int main()
{
       // freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,disk;
 t=0;
   while(sf("%d %d",&disk,&mov)==2)
   {
       ++t;
       if(disk==0&&mov==0)
        break;
       A.clear();
       B.clear();
       C.clear();
       for(i=disk;i>=1;i--)
        A.push_back(i);
    pf("Problem #%d\n",t);
    mv=0;
        pf("\nA=>");
        for(i=0;i<A.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",A[i]);
        }
        pf("\nB=>");
        for(i=0;i<B.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",B[i]);
        }
        pf("\nC=>");
        for(i=0;i<C.size();i++)
        {
            if(i==0)
                pf("   ");
            else
                pf(" ");
            pf("%d",C[i]);
        }
        pf("\n");
    solve(disk,1,2,3);
    pf("\n");
   }
    return 0;
}
