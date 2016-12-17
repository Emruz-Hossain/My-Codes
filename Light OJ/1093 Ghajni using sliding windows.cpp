//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define     sf scanf
#define     pf printf
int main()
{
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx,mn;
   sf("%d",&t);
   for(x=1;x<=t;x++)
   {
       sf("%d %d",&n,&d);
       deque< pair<int,int> >DQ1,DQ2;
       sm=0;
       for(i=0;i<n;i++)
       {
           sf("%d",&p);
           while(!DQ1.empty()&&DQ1.back().first>=p)
            DQ1.pop_back();
           DQ1.push_back(make_pair(p,i));
           while(DQ1.front().second<=i-d)
            DQ1.pop_front();
           mn=DQ1.front().first;
           while(!DQ2.empty()&&DQ2.back().first<=p)
            DQ2.pop_back();
           DQ2.push_back(make_pair(p,i));
           while(DQ2.front().second<=i-d)
            DQ2.pop_front();
           mx=DQ2.front().first;
           sm=max(sm,mx-mn);
       }
       pf("Case %d: %d\n",x,sm);
   }

    return 0;
}
