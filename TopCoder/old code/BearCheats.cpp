//BISMILLAHIR RAHMANIR RAHIM
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

struct BearCheats{
string eyesight(int A, int B)
{
    string ret="glasses";
    int cnt=0,d1,d2;
    while(A>0&&B>0)
    {
      d1=A%10;
      A/=10;
      d2=B%10;
      B/=10;
      if(d1!=d2)
            cnt++;
    }
    if(cnt<=1&&A==0&&B==0)
    return "happy";

    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8072; int Arg1 = 3072; string Arg2 = "happy"; verify_case(0, Arg2, eyesight(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 508; int Arg1 = 540; string Arg2 = "glasses"; verify_case(1, Arg2, eyesight(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 854000; int Arg1 = 854000; string Arg2 = "happy"; verify_case(2, Arg2, eyesight(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 6; string Arg2 = "happy"; verify_case(3, Arg2, eyesight(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 385900; int Arg1 = 123000; string Arg2 = "glasses"; verify_case(4, Arg2, eyesight(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
BearCheats ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
