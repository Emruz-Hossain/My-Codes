//12102015 1224 loj 1343
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
#define FR first
#define SC second
#define MKP make_pair
#define PI acos(-1)
#define INF INT_MAX
#define EPS 1e-9
#define MX 507
#define MOD (1LL<<32)

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
int dxx[] = {0, 0, 0, 0, +1, +1, -1, -1};
int dyy[] = {+1, +1, -1, -1, 0, 0, 0, 0};

inline bool EQ(double a, double b) { return fabs(a-b) < EPS; }

struct data
{
	int sum, i, j;
	data(){}
	data(int a, int b, int c) {
		sum = a;
		i = b;
		j = c;
	}
	bool operator < (const data& w) const {
		return sum == w.sum ? i < w.i : sum < w.sum;
	}
};

long long tree[MX][MX];
int a[MX], n;
vector<pair<int, pair<int, int> > > v;

void update(int idx, int idy, long long val)
{
	int y = idy;
	while(idx <= n) {
		idy = y;
		while(idy <= n) {
			tree[idx][idy] = (tree[idx][idy] + val) % MOD;
			idy += (idy & -idy);
		}
		idx += (idx & -idx);
	}
}

long long query(int idxi, int idyi, int idxj, int idyj)
{
	long long sum = 0;
	int yi = idyi, yj = idyj;

	while(idxi <= idxj) {
		idyi = yi, idyj = yj;
		while(idyi <= idyj) {
			sum = (sum + tree[idxj][idyj]) % MOD;
			idyj -= (idyj & -idyj);
		}

		idyi--;
		while(idyi != idyj) {
			sum = ((sum - tree[idxj][idyi]) % MOD + MOD) % MOD;
			idyi -= (idyi & -idyi);
		}

		idxj -= (idxj & -idxj);
	}

	idxi--;
	while(idxi != idxj) {
		idyi = yi, idyj = yj;
		while(idyi <= idyj) {
			sum = ((sum - tree[idxi][idyj]) % MOD + MOD) % MOD;
			idyj -= (idyj & -idyj);
		}

		idyi--;
		while(idyi != idyj) {
			sum = (sum + tree[idxi][idyi]) % MOD;
			idyi -= (idyi & -idyi);
		}

		idxi -= (idxi & -idxi);
	}

	return sum;
}

int main()
{
	int tc, cs, x, y, sum;
	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs ++) {

		scanf("%d", &n);
		for(x = 1; x <= n; x ++)
			for(y = 1; y <= n; y ++)
				tree[x][y] = 0;

		for(x = 1; x <= n; x ++) {
			scanf("%d", &a[x]);
		}

		for(x = 1; x <= n; x ++) {
			for(y = x + 1; y <= n; y ++) {
				sum = a[x] + a[y];
				v.PB(MKP(sum, MKP(x, y)));
				//v.PB(data(sum, x, y));
			}
		}

		sort(v.begin(), v.end());

		for(x = 0; x < (int) v.size(); x ++) {
			update(v[x].SC.FR, v[x].SC.SC, query(v[x].SC.FR + 1, v[x].SC.FR + 1, v[x].SC.SC - 1, v[x].SC.SC - 1) + 1);
			//update(v[x].i, v[x].j, query(v[x].i + 1, v[x].i + 1, v[x].j - 1, v[x].j - 1) + 1);
		}

		printf("Case %d: %lld\n", cs, query(1, 1, n, n));
		v.clear();
	}
        return 0;
}
