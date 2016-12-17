//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100011

int n, m, k, tree[maxN * 2];
ii a[maxN], b[maxN];

int get(int i) {
	int res = 0;
	while (i) {
		res += tree[i];
		i -= AND(-i, i);
	}
	return res;
}

int update(int i, int val) {
	while (i <= k) {
		tree[i] += val;
		i += AND(-i, i);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		rep(i, n) {
			scanf("%d %d", &a[i].ff, &a[i].ss);
			if (a[i].ff > a[i].ss) swap(a[i].ff, a[i].ss);
		}
		rep(i, m) {
			scanf("%d %d", &b[i].ff, &b[i].ss);
			if (b[i].ff > b[i].ss) swap(b[i].ff, b[i].ss);
		}
		sort(a, a + n);
		sort(b, b + m);
		int64 res = 0LL;
		k = n + m;
		fr(i, 0, k) tree[i] = 0;
		for (int i = n - 1, j = m - 1; i >= 0; i--) {
			while (j >= 0 && b[j].ff >= a[i].ff) {
				update(b[j].ss, 1);
				j--;
			}
			res += get(a[i].ss);
		}
		fr(i, 0, k) tree[i] = 0;
		for (int i = m - 1, j = n - 1; i >= 0; i--) {
			while (j >= 0 && a[j].ff > b[i].ff) {
				update(a[j].ss, 1);
				j--;
			}
			res += get(b[i].ss);
		}
		printf("Case %d: %lld\n", ++caseNo, res);
	}
	return 0;
}
