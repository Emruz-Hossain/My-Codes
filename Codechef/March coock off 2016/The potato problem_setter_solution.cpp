#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct pt {
	long long x,y;

	bool operator<(const pt &P) const {
		if(P.x != x) return x < P.x;
		return y < P.y;}
	};

long long vs(pt A, pt B, pt O) {
	return (A.x-O.x)*(B.y-O.y)-(B.x-O.x)*(A.y-O.y);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int N;
		cin >> N;
		vector<pt> P(N);
		for(int i =0; i < N; i++) cin >> P[i].x >> P[i].y;
		sort(begin(P),end(P));

		vector<int> H[2];
		H[0].push_back(0);
		H[1].push_back(0);
		for(int i =1; i < N; i++) {
			if(vs(P[i],P[N-1],P[0]) <= 0) {
				while((int)H[0].size() > 1 && vs(P[H[0].back()],P[i],P[H[0][H[0].size()-2]]) >= 0) H[0].pop_back();
				H[0].push_back(i);}
			if(vs(P[i],P[N-1],P[0]) >= 0) {
				while((int)H[1].size() > 1 && vs(P[H[1].back()],P[i],P[H[1][H[1].size()-2]]) <= 0) H[1].pop_back();
				H[1].push_back(i);}
			}
		vector<int> Hc =H[0];
		for(int i =H[1].size()-2; i > 0; i--) Hc.push_back(H[1][i]);

		vector<bool> inH(N,false);
		for(int i =0; i < 2; i++) {
			ALL_THE(H[i],it) inH[*it] =true;
			H[i].clear();}
		int mi =0, mx =N-1;
		while(mi < N && inH[mi]) mi++;
		if(mi == N) {
			cout << "-1\n";
			continue;}
		while(inH[mx]) mx--;

		H[0].push_back(mi);
		H[1].push_back(mi);
		for(int i =mi+1; i <= mx; i++) if(!inH[i]) {
			if(vs(P[i],P[mx],P[mi]) <= 0) {
				while((int)H[0].size() > 1 && vs(P[H[0].back()],P[i],P[H[0][H[0].size()-2]]) >= 0) H[0].pop_back();
				H[0].push_back(i);}
			if(vs(P[i],P[mx],P[mi]) >= 0) {
				while((int)H[1].size() > 1 && vs(P[H[1].back()],P[i],P[H[1][H[1].size()-2]]) <= 0) H[1].pop_back();
				H[1].push_back(i);}
			}

		vector<int> Hi =H[0];
		for(int i =H[1].size()-2; i > 0; i--) Hi.push_back(H[1][i]);

		int a =0, n =Hc.size(), m =Hi.size();
		long long dif =1e18;
		for(int i =0; i < n; i++) {
			long long S0 =abs(vs(P[Hi[a]],P[Hc[i]],P[Hc[(i+1)%n]]));
			while(true) {
				long long Sn =abs(vs(P[Hi[(a+1)%m]],P[Hc[i]],P[Hc[(i+1)%n]]));
				if(Sn >= S0) break;
				a =(a+1)%m;
				S0 =Sn;}
			while(true) {
				long long Sn =abs(vs(P[Hi[(a+m-1)%m]],P[Hc[i]],P[Hc[(i+1)%n]]));
				if(Sn >= S0) break;
				a =(a+m-1)%m;
				S0 =Sn;}
			dif =min(dif,abs(vs(P[Hi[a]],P[Hc[i]],P[Hc[(i+1)%n]])));
			}

		long long ans =-dif;
		for(int i =2; i < n; i++) ans +=abs(vs(P[Hc[i]],P[Hc[i-1]],P[Hc[0]]));
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing
