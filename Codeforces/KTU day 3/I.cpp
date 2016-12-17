//BISMILLAHIR RAHMANIR RAHIM
// OUM NAMA MA SWARASATI

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define cl(vctr) vctr.clear()
#define ms(v, ar) memset(ar, v, sizeof(ar))

#define inf 1 << 30
#define pi (double)(2.0 * acos( 0.0 ))
#define eps 1E-9
#define sz 100000 + 5
#define mod 1000000000 + 7

using namespace std;
typedef long long int ll;

int main()
{
    double A,B,R;
    scanf("%lf %lf %lf",&A,&B,&R);
    int cnt=0;

        double pii=pi;
        double n2=pii/asin(R/(R+B))+eps;
        double n1= pii/asin(R/(R+A))-eps ;
        cnt=(int)(n2)-(int)n1;
    printf("%d\n",cnt);

    return 0;
}
