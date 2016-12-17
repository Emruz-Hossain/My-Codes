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

struct ForgetfulAddition{
int minNumber(string expression)
{
    int ret,l,n1,n2,m1,m2,sm1=0,sm2=0,cnt1=0,cnt2=0,i;
    l=expression.size();
    n1=l/2;
    m1=l-n1;
    m2=l/2;
    n2=l-m2;
    for(i=0;i<n1;i++)
        sm1=sm1*10+expression[i]-48;
    for(i=n1;i<l;i++)
        cnt1=cnt1*10+expression[i]-48;
    for(i=0;i<n2;i++)
        sm2=sm2*10+expression[i]-48;
    for(i=n2;i<l;i++)
        cnt2=cnt2*10+expression[i]-48;
    return ret=min(sm1+cnt1,sm2+cnt2);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "22"; int Arg1 = 4; verify_case(0, Arg1, minNumber(Arg0)); }
	void test_case_1() { string Arg0 = "123"; int Arg1 = 15; verify_case(1, Arg1, minNumber(Arg0)); }
	void test_case_2() { string Arg0 = "1289"; int Arg1 = 101; verify_case(2, Arg1, minNumber(Arg0)); }
	void test_case_3() { string Arg0 = "31415926"; int Arg1 = 9067; verify_case(3, Arg1, minNumber(Arg0)); }
	void test_case_4() { string Arg0 = "98765"; int Arg1 = 863; verify_case(4, Arg1, minNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ForgetfulAddition ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
