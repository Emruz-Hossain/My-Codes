


//BISMILLAHIR RAHMANIR RAHIM
// OUM NAMA MA SWARASATI

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define cl(vctr) vctr.clear()
#define ms(v, ar) memset(ar, v, sizeof(ar))

#define inf 1 << 30
#define pi (double)(2.0 * acos( 0.0 ))
#define eps 1E-9
#define sz 100000 + 5
#define mod 1000000000 + 7

using namespace std;
typedef long long int ll;

ll ar[sz];

void pf(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        (i-1)&&printf(" ");
        printf("%I64d",ar[i]);
    }
    printf("\n");
}

int main()
{
    ll n,p,q;

    scanf("%I64d %I64d %I64d",&n,&p,&q);ll mx=n*(n+1)/2;

    if(p>mx)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    ll xx,i,j,k;
    for(i=1;i<=n;i++)
    {
        if((p*i)%q==0)
        {
            xx=(p*i)/q;
            ll s=i*(i+1)/2,e=mx-(n-i)*(n-i+1)/2;
            if(xx>=s&&xx<=e)
            {
                break;
            }
        }
    }
    if(i>n)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vector<ll>v;
    ll cnt =i;
    ll last=n;
    ll tmp;
    while(cnt)
    {
        tmp=cnt-1;
        ll d;
        if(tmp==1)
           d=xx-1;
        else
            d=xx-(tmp*(tmp+1))/2;
        if(d>=last)
        {
            v.push_back(last);
            xx=xx-last;
            last=last-1;
            cnt--;
        }
        else
        {
            v.push_back(d);
            last=d-1;
            if(tmp==1)
                xx=1;
            else
             xx=(tmp*(tmp+1))/2;
            cnt--;
        }

    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        if(i>0)
            printf(" ");
        printf("%I64d",v[i]);
    }
    printf("\n");

    return 0;
}
