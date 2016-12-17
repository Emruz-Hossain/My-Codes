#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz size()
typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;
const int N = 100001;
const int BSZ = 320;
int A[N];
map<int, int > M;
map<int, int >::iterator it;
int n,q;
LL ans[N];
struct Qnode
{
  int l,r,idx;
};
Qnode Q[N];
int BIT1[N], BIT2[N], T[N];
int tm;
bool cmp(const Qnode &x, const Qnode &y)
{
  if(x.l / BSZ == y.l / BSZ) return x.r < y.r;
  return x.l / BSZ < y.l / BSZ;
}
void update1(int idx, int val)
{
  for(int i = idx; i < N; i += i & -i)
    BIT1[i] += val;
}
void update2(int idx, int val)
{
  for(int i = idx; i < N; i += i & -i)
  {
    if(T[i] != tm)
    {
      BIT2[i] = 0;
    }
    T[i] = tm;
    BIT2[i] += val;
  }
}
int query1(int idx)
{
  int res = 0;
  for(int i = idx; i; i -= i & -i)
  {
    res += BIT1[i];
  }
  return res;
}
int query2(int idx)
{
  int res = 0;
  for(int i = idx; i; i -= i & -i)
  {
    if(T[i] != tm)
    {
      BIT2[i] = 0;
    }
    T[i] = tm;
    res += BIT2[i];
  }
  return res;
}
void solve()
 {
  int start = 0, end = 0;
  LL res = 0;
  rep(i,0,q)
  {
    int l = Q[i].l, r = Q[i].r;
    if (l >= start)
    {
      start = (l / BSZ + 1) * BSZ;
      end = start;
      res = 0;
      memset(BIT1, 0, sizeof(BIT1));
    }
    while (end <= r)
    {
      res += query1(N-1) - query1(A[end]);
      update1(A[end], 1);
      end++;
    }
    LL tmp = res;
    tm++;
    for (int j = min(start-1, r); j >= l; j--)
    {
      tmp += query1(A[j] - 1) + query2(A[j] - 1);
      update2(A[j], 1);
    }
    ans[Q[i].idx] = tmp;
  }
  rep(i,0,q) printf("%lld\n",ans[i]);
}
int main() {
    freopen("xinput.txt","r",stdin);
    freopen("out2.txt","w",stdout);
  S2(n,q);
  rep(i,0,n) {
    S(A[i]);
    M[A[i]] = 0;
  }
  int cnt = 1;
  for(it = M.begin(); it != M.end(); it++) {
    it->second = cnt++;
  }
  rep(i,0,n) {
    A[i] = M[A[i]];
  }
  rep(i,0,q) {
    scanf("%d%d",&Q[i].l, &Q[i].r);
    Q[i].l--;
    Q[i].r--;
    Q[i].idx = i;
  }
  sort(Q, Q+q, cmp);
  solve();
  return 0;
}
