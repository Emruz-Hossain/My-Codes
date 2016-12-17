#include <bits/stdc++.h>
using namespace std;

const double inf=10000000000000.0;

double bs(double l, double h, double arc, double len) {
	double r = 0.0;

	for(int i = 0; i < 100; ++i) {
		r = (l+h)/2.0;

		double A = arc/r;
		double chord = 2.0*r*sin(A/2.0);

		if(chord > len) h = r;
		else l = r;
	}
	return r - sqrt( r*r - len*len/4.0);
}

int main () {
	int t;
	double l, n, c;

	scanf("%d", &t);

	for(int cs = 1; cs <= t; ++cs) {
		scanf("%lf %lf %lf", &l, &n, &c);

		double arc = (1.0 + n*c)*l;
		printf("Case %d: %.9lf\n", cs, bs(0, inf, arc, l));
	}

	return 0;
}
