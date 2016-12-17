#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cctype>
#include<sstream>

#include<vector>
#include<list>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
using namespace std;

#define inf 100000000
#define REP(i, n) for(int i = 1; i <= n; ++i)

//input
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld%lld", &a, &b)
#define slll(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define sd(a) scanf("%lf", &a)
#define sc(a) scanf("%c", &a)
#define sst(a) scanf("%s", a)
#define pii pair<int, int>
#define F first
#define S second


#define MX 505

pii a[MX];
int dp[2][MX][MX];

int main () {
	int t, m, f, c, r;

	scanf("%d", &t);

	while(t--) {
		scanf("%d %d %d %d", &m, &f, &r, &c);

		c = min(1, c);

		for(int i = 1; i <= r; ++i) scanf("%d %d", &a[i].F, &a[i].S);
		for(int i = 0; i <= m; ++i) for(int j = 0; j <= f; ++j)  dp[0][i][j] = dp[1][i][j] = inf;

		dp[0][0][0] = 0;
		for(int i = 1; i <= r; ++i) {
			for(int j = 0; j <= m; ++j) {
				for(int k = 0; k <= f; ++k) {
						int curr = (i&1);
						int prev = (curr^1);
						dp[curr][j][k] = dp[prev][j][k];
						if(j) dp[curr][j][k] = min(dp[curr][j][k], a[i].S + dp[prev][max(0, j-a[i].F)][k]);
						if(k) dp[curr][j][k] = min(dp[curr][j][k], a[i].S + dp[prev][j][max(0, k-a[i].F)]);
						if(c && j && k && a[i].F > 1) dp[curr][j][k] = min(dp[curr][j][k], a[i].S + dp[prev][j-1][k-1]);
				}
			}
		}
		int ans;
		if(r%2==0)
            ans=dp[0][m][f];
        else
            ans=dp[1][m][f];

		if(ans >= inf) printf("Impossible\n");
		else printf("%d\n", ans);
	}

	return 0;
}
