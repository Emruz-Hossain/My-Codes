//BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define     mem(x,y) memset(x,y,sizeof(x))
#define     PB(x) push_back(x)
#define     POB() pop_back()
#define     SZ(a) a.size()
#define     len(a) strlen(a)
#define     sf scanf
#define     pf printf

#define     inf 1<<25
#define     sz 2000
#define     eps 1e-9
#define     mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2};

//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}

struct ZigZag{
    int ar[60],dp[60][60][3],n;
    int rec(int ind,int prev,int sgn)
    {
        int p=0,q=0;
        if(ind>=n)
            return 0;
        if(dp[ind][prev][sgn]!=-1)
            return dp[ind][prev][sgn];
        if(sgn==0)
        {
            if(prev==0)
            {
                p=rec(ind+1,ind,0)+1;
                q=rec(ind+1,prev,0);
                return dp[ind][prev][sgn]=max(p,q);
            }
            if(ar[prev]-ar[ind]>0)
            {
                p=rec(ind+1,ind,1)+1;
            }
            else if(ar[prev]-ar[ind]<0)
            {
                p=rec(ind+1,ind,2)+1;
            }
            q=rec(ind+1,prev,0);
            return dp[ind][prev][sgn]=max(p,q);
        }
        else
        {
            p=rec(ind+1,prev,sgn);
            if(sgn==1&&ar[prev]-ar[ind]<0)
            {
                q=rec(ind+1,ind,2)+1;
            }
            else if(sgn==2&&ar[prev]-ar[ind]>0)
                q=rec(ind+1,ind,1)+1;
            return dp[ind][prev][sgn]=max(p,q);
        }
    }
int longestZigZag(vector <int> sequence)
{
    int ret,i;
    n=sequence.size()+1;
    for(i=1;i<n;i++)
        ar[i]=sequence[i-1];
    mem(dp,-1);
    return ret=max(rec(2,0,0),rec(2,1,0)+1);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 7, 4, 9, 2, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, longestZigZag(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, longestZigZag(Arg0)); }
	void test_case_2() { int Arr0[] = { 44 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, longestZigZag(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, longestZigZag(Arg0)); }
	void test_case_4() { int Arr0[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, longestZigZag(Arg0)); }
	void test_case_5() { int Arr0[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(5, Arg1, longestZigZag(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ZigZag ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
