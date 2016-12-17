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

struct ToastXRaspberry{
int apply(int upper_limit, int layer_count)
{
    int ret=0,r=0;
    while(r<layer_count)
    {
        ret+=1;
        if(r+upper_limit<=layer_count)
            r+=upper_limit;
        else
            break;

    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 13; int Arg2 = 4; verify_case(0, Arg2, apply(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 5; int Arg2 = 1; verify_case(1, Arg2, apply(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 73; int Arg1 = 265; int Arg2 = 4; verify_case(2, Arg2, apply(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ToastXRaspberry ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
