/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


LL X[500001], Y[500001], mx[500001];
pair < LL, LL > pp[500001], ar[1000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        freopen("Noutput.txt","w",stdout);
        freopen("C-small-practice.in","r",stdin);
    int T; cin >> T;
    FOR(ts, 1, T+1) {
        int n; cin >> n >> X[1] >> Y[1];
        LL A, B, C1, C2, M; cin >> A >> B >> C1 >> C2 >> M;
        FOR(i, 2, n+1){
            X[i] = (A*X[i-1]+B*Y[i-1]+C1) % M;
            Y[i] = (A*Y[i-1]+B*X[i-1]+C2) % M;
        }
        FOR(i, 1, n+1) if(X[i] > Y[i]) swap(X[i], Y[i]);
        FOR(i, 1, n+1) pp[i] = mp(Y[i], X[i]);
        sort(pp + 1, pp + n + 1);

        int cnt = 0;
        FOR(i, 1, n+1) {
            X[i] = pp[i].yy;
            Y[i] = pp[i].xx;
            ar[cnt++] = mp(X[i], -i);
            ar[cnt++] = mp(Y[i], i);
        }


        set0(mx);

        sort(ar, ar + cnt);
        set < int > S;
        LL last = 0, lastAny = 0, sum = 0;
        REP(i, cnt){
            if(ar[i].yy < 0){
                if(S.size() == 0) last = ar[i].xx;
                if(S.size() == 1){
//                    cout << ar[i].xx << " " << lastAny << endl;
                    mx[(*S.begin())] += ar[i].xx - lastAny;
                }
                S.insert(-ar[i].yy);
                if(S.size() == 1) lastAny = max(lastAny, ar[i].xx);
            } else {
                if(S.size() == 1){
//                        cout << ar[i].xx << " " << lastAny << endl;
                    mx[(*S.begin())] += ar[i].xx - lastAny+1;
                }
                S.erase(ar[i].yy);
                if(S.empty()) sum += ar[i].xx - last+1;
                if(S.size() == 1) lastAny = max(lastAny, ar[i].xx+1);
            }
        }

//        cout << sum << endl;

        LL res = sum;
        FOR(i, 1, n+1) res = min(res, sum - mx[i]);
        cout << "Case #" << ts << ": " << res << endl;
    }
}
