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
 int dp[55][55][3];
int rec(string S,int ind,int ugl,int prev)
{
    int p,q;
    if(ind>=S.size())
        return ugl;
    if(dp[ind][ugl][prev]!=-1)
        return dp[ind][ugl][prev];
    if(ind>0)
    {
        if(S[ind]=='?')
        {
            if(S[ind-1]=='A')
            {
                S[ind]='A';
               p=rec(S,ind+1,ugl+1,0);
                S[ind]='?';
                S[ind]='B';
                q=rec(S,ind+1,ugl,1);
                S[ind]='?';
                return dp[ind][ugl][prev]=min(p,q);
            }
            else
            {
                 S[ind]='A';
                p=rec(S,ind+1,ugl,0);
                S[ind]='?';
                S[ind]='B';
                q=rec(S,ind+1,ugl+1,1);
                S[ind]='?';
                return dp[ind][ugl][prev]=min(p,q);
            }
        }
        else
        {
            if(S[ind-1]==S[ind])
            {
                if(S[ind]=='A')
                return dp[ind][ugl][prev]=rec(S,ind+1,ugl+1,0);
                else
                     return dp[ind][ugl][prev]=rec(S,ind+1,ugl+1,1);
            }
            else
            {
                if(S[ind]=='A')
                return dp[ind][ugl][prev]=rec(S,ind+1,ugl,0);
                else
                    return dp[ind][ugl][prev]=rec(S,ind+1,ugl,1);
            }

        }

    }
    else
    {
           if(S[ind]=='?')
           {
             S[ind]='A';
                p=rec(S,ind+1,ugl,0);
                S[ind]='?';
                S[ind]='B';
                q=rec(S,ind+1,ugl,1);
                S[ind]='?';
                return dp[ind][ugl][prev]=min(p,q);
           }
           else
           {
               if(S[ind]=='A')
               return dp[ind][ugl][prev]=rec(S,ind+1,ugl,0);
               else
                return dp[ind][ugl][prev]=rec(S,ind+1,ugl,1);
           }

    }
}
struct TaroFillingAStringDiv2{
int getNumber(string S)
{
    int ret;
    memset(dp,-1,sizeof(dp));
    return ret=rec(S,0,0,0);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?A?ABA?B??BAA?B?B?AA?A?BAAAA??A???BAA?AAABA?"; int Arg1 = 15; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "B?ABAABAB?"; int Arg1 = 2; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "A?A"; int Arg1 = 0; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "A??B???AAB?A???A"; int Arg1 = 3; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "?BB?BAAB???BAB?B?AAAA?ABBA????A?AAB?BBA?A?"; int Arg1 = 10; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
TaroFillingAStringDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
