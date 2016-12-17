//02032016 1132 cf 632E
/*
ID: kfoozmi1
LANG: C++
TASK:
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef kfoozminus
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu() {
	cerr << endl;
}

template <typename T>
void faltu(T a[], int n) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename First, typename ... hello>
void faltu(First arg, const hello&... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}
#else
#define dbg(args...)
#endif

#define PB push_back
#define F first
#define S second
#define MKP make_pair
#define PI acos(-1)
#define INF 100000000
#define EPS 1e-9

#define B1 43
#define B2 43

#define MOD  1000000007
#define MOD1 1000000007
#define MOD2 1000000009

#define MX 100007

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dxx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
int dyy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool checkBit(ll n, int i) { return n & (1LL << i); }
inline ll setBit(ll n, int i) { return n | (1LL << i); }
inline ll resetBit(ll n, int i) { return n & (~ (1LL << i)); }
inline bool EQ(double a, double b) { return fabs(a-b) < EPS; }

ll bigMod(ll a, ll b)
{
	ll r = 1;
	while(b) {
		if(b & 1) (r *= a) %= MOD;
		b >>= 1;
		(a *= a) %= MOD;
	}
	return r;
}

int dp[1000007], a[1007];

int main()
{
#ifdef kfoozminus
	//freopen("in", "r", stdin);
#endif
	int n, k, i, mn, mx, j;

	mn = 1001;
	mx = 0;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i ++) {
		scanf("%d", &a[i]);
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	for(i = 0; i < n; i ++) a[i] -= mn;
	mx = (mx - mn) * k;
	for(i = 0; i <= mx; i ++) dp[i] = INF;
	dp[0] = 0;
	for(i = 0; i < n; i ++) {
		for(j = 0; j <= mx; j ++) {
			if(a[i] <= j) {
				dp[j] = min(dp[j], dp[j - a[i]] + 1);
			}
		}
	}

	for(i = 0; i <= mx; i ++) if(dp[i] <= k) printf("%d ", i + mn * k); printf("\n");

        return 0;
}
