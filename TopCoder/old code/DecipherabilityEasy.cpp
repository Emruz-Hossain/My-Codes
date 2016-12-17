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

struct DecipherabilityEasy{
string check(string s, string t)
{
    int i,j,cnt;
    cnt=0;
    for(i=0,j=0;j<s.size();)
    {
        if(t[i]!=s[j]||i==t.size())
        {
            cnt++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    if(cnt==1)
        return "Possible";
    else
        return "Impossible";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sunuke"; string Arg1 = "snuke"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcd"; string Arg1 = "abcd"; string Arg2 = "Impossible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "snuke"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "snukent"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arg1 = "aaaa"; string Arg2 = "Possible"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaa"; string Arg1 = "aaa"; string Arg2 = "Impossible"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "topcoder"; string Arg1 = "tpcoder"; string Arg2 = "Possible"; verify_case(6, Arg2, check(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "singleroundmatch"; string Arg1 = "singeroundmatc"; string Arg2 = "Impossible"; verify_case(7, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
DecipherabilityEasy ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
