 #include<stdio.h>
 #include<math.h>
 #include<stdlib.h>
 #include<string.h>
 #include<algorithm>
 using namespace std;
 typedef long long ll;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     sf  scanf
#define     pf  printf


#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)


 /**************************************************Code start from here**************************/
pair<ll,ll>dp[200005][3];
ll ar[200005],n;
char ss[200005];
pair<ll,ll> rec(ll idx,ll rem)
{
    pair<ll,ll> &ret=dp[idx][rem];
    if(idx>=n)
    {
        pair<ll,ll> p;
        if(rem==0LL)
        {
            p.second=1;
            p.first=0;
        }
        else
        {
            p.second=0;
            p.first=0;
        }
        return p;
    }
    if(ret.first!=-1LL)
        return ret;
    pair<ll,ll> sm;
    sm.first=0;
    sm.second=0;
    if(ss[idx]=='?')
    {
        pair<ll,ll> p;
        p=rec(idx+1,rem);
        if(p.second==1LL&&sm.first<=p.first+ar[idx])
        {
            sm.first=p.first+ar[idx];
            sm.second=p.second;
        }
        if(rem>0LL)
        {
            p=rec(idx+1,rem-1);
             if((p.second==1LL)&&(sm.first<=p.first+ar[idx]))
            {
                sm.first=p.first+ar[idx];
                sm.second=p.second;
           }
        }
        p=rec(idx+1,rem);
        if(p.second==1LL&&sm.first<=p.first)
        {
            sm.first=p.first;
            sm.second=p.second;
        }
        if(rem>0LL)
        {
            p=rec(idx+1,rem-1);
            if(p.second==1LL&&sm.first<=p.first)
            {
                sm.first=p.first;
                sm.second=p.second;
            }
        }

    }
    else
    {
        pair<ll,ll>p;
        if(ss[idx]=='0')
        {
             p=rec(idx+1,rem);
            if(p.second==1LL&&sm.first<=p.first)
            {
                sm.first=p.first;
                sm.second=p.second;
            }
            if(rem>0LL)
            {
                p=rec(idx+1,rem-1);
                if(p.second==1LL&&sm.first<=p.first+ar[idx])
                {
                    sm.first=p.first+ar[idx];
                    sm.second=p.second;
                }
            }

        }
        else
        {
            p=rec(idx+1,rem);
            if(p.second==1LL&&sm.first<=p.first+ar[idx])
            {
                sm.first=p.first+ar[idx];
                sm.second=p.second;
            }
            if(rem>0LL)
            {
                p=rec(idx+1,rem-1);
                if(p.second==1LL&&sm.first<=p.first)
                {
                    sm.first=p.first;
                    sm.second=p.second;
                }
            }
        }
    }
    return ret=sm;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   ll a,b,c,d,h,m,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   sf("%I64d",&t);
   for(x=1;x<=t;x++)
   {
       sf("%s",&ss);
       n=(long long)strlen(ss);
       for(i=0;i<n;i++)
        sf("%I64d",&ar[i]);
      for(i=0;i<=n;i++)
      {
          dp[i][1LL].first=-1LL;
          dp[i][0LL].first=-1LL;
          dp[i][1LL].second=0LL;
          dp[i][0LL].second=0LL;
      }
       pf("Case #%I64d: %I64d\n",x,rec(0LL,1LL).first);
   }
    return 0;
}




