//BISMILLAHIR RAHMANIR RAHIM
//http://www.boi2007.de/tasks/sound.pdf
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
    //freopen("2.txt","r",stdin);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,mx,mn,flag;
   deque< pair<int,int> >DQ1,DQ2;
       while(sf("%d %d %d",&n,&d,&c)==3)
       {
       sm=0;
       flag=0;
       for(i=0;i<n;i++)
       {
           sf("%d",&p);
           if(i>=d)
           {
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
          if(mx-mn<=c)
          {
              pf("%d\n",i);
              flag=1;
          }
          }
          else
          {
              DQ1.push_back(make_pair(p,i));
              DQ2.push_back(make_pair(p,i));
          }

       }
       if(!flag)
        pf("NONE\n");
       }

    return 0;
}
