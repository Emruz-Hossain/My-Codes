#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll bug(ll Q, ll arr[], ll n){
    ll lo=0, hi=n, mid, best = -1;
    while(lo<=hi){
        ll mid = lo + (hi-lo)/2;
        if(arr[mid]>=Q){
             best = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return best;
}
ll valluk(ll Q, ll arr[], ll n){
    ll lo=0, hi=n;
    ll best_so_far=-1;
    while(lo<=hi){
        ll mid =lo + (hi-lo)/2;
        if(arr[mid]<=Q){

                best_so_far=mid;
            lo=mid+1;
        }else hi=mid-1;
    }
    return best_so_far;
}
int main()
{
   ll t , n, m;
    scanf("%lli ", &t);
    for(ll j = 1; j<= t; j++){
    scanf(" %lli %lli", &n, &m);
            printf("Case %lli:\n", j );
    ll f, s;
    ll arr[n+12];
    ll mx=-1;
    for(ll i = 0; i<n; i++)
    {
        scanf("%lli", &arr[i]);
        mx=max(mx,arr[i]);
    }
    for(ll i = 0; i<m; i++){
        scanf("%lli %lli", &f , &s );
        if(f>mx)
            printf("0\n");
        else
        printf("%lli\n", valluk(s, arr, n-1) - bug(f, arr, n-1) +1);
    }
    }
}
