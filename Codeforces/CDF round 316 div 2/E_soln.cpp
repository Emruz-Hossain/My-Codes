#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define mem(a, b) memset(a, b, sizeof(a))
#define PI acos(-1)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a)*(a))
#define inf 100000000
#define mod 1000000007
#define eps 1e-9

//loop
#define rep(i, n) for(int i = 0; i < n; ++i)
#define fi(i, n) for(int i = 0; i <= n; ++i)

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

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << ": "; DBG, args; cerr << endl; } while(0)
#define deb(a, n) cerr << #a << ": "; for(int i = 0; i < n; ++i) cerr << a[i] << " "; cerr << endl;

struct debugger {
	template <typename T> debugger &operator , (const T &v) {
		cerr << v << ' ';
		return *this;
	}
} DBG;


//Direction Array
//int fx[]={1, -1, 0, 0};
//int fy[]={0, 0, 1, -1};
//int fx[]={0, 0, 1, -1, -1, 1, -1, 1};
//int fy[]={-1, 1, 0, 0, 1, 1, -1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

//bit manipulation
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }
//end of template

char a[502][502];
ll dp[2][502][502];

int main () {
	int n, m;

	sii(n, m);

	rep(i, n) sst(a[i]);

	if(a[0][0] != a[n-1][m-1]) return puts("0")&0;

	dp[0][0][n-1] = 1;

	ll ans = 0;
	int layer = 0;
	for(int moves = 1; moves <= (n+m-2)/2; ++moves) {
		layer = 1-layer;

		for(int r1 = 0; r1 < n; ++r1) {
			if(r1 > moves) continue;
			for(int r2 = n-1; r2 >= 0; --r2) {
				if(n-1-r2 > moves) continue;
				int c1 = moves-r1;
				int c2 = (m-1)-(moves-(n-1-r2));

				if(c1 < 0 || c1 >= m || c2 >= m || c2 < 0) continue;

				ll &res = dp[layer][r1][r2];

				res = 0;

				if(a[r1][c1] != a[r2][c2]) continue;

				if(c1-1 >= 0 && c2+1 < m) res = (res + dp[1-layer][r1][r2])%mod;
				if(c1-1 >= 0 && r2+1 < n) res = (res + dp[1-layer][r1][r2+1])%mod;
				if(r1-1 >= 0 && c2+1 < m) res = (res + dp[1-layer][r1-1][r2])%mod;
				if(r1-1 >= 0 && r2+1 < n) res = (res + dp[1-layer][r1-1][r2+1])%mod;

				if(moves == (n+m-2)/2) {
					if(r1 == r1 && c1 == c2) ans += res;
					else if(r1 +1 == r2 && c1 == c2) ans += res;
					else if(r1 == r2 && c1+1 == c2) ans += res;
					ans %= mod;
				}
			}
		}
	}
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
        printf("%lld ",dp[layer][i][j]);
    printf("\n");
}
	printf("%lld\n", ans);

	return 0;
}
