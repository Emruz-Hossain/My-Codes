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

struct JanuszInTheCasino{
double findProbability(long long n, int m, int k)
{
    double ret;
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.75; verify_case(0, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; int Arg1 = 3; int Arg2 = 3; double Arg3 = 0.2962962962962962; verify_case(1, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 4LL; int Arg1 = 3; int Arg2 = 2; double Arg3 = 1.0; verify_case(2, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 5LL; int Arg1 = 4; int Arg2 = 5; double Arg3 = 0.87109375; verify_case(3, Arg3, findProbability(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 1000000000000LL; int Arg1 = 2; int Arg2 = 40; double Arg3 = 0.9094947017729282; verify_case(4, Arg3, findProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
JanuszInTheCasino ___test;
___test.run_test(-1);
int gbase;  
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
