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

struct MissingParentheses{
int countCorrections(string par)
{
    int i,k,j,r;
    char ss[100];
    for(i=0;i<par.length();i++)
        ss[i]=par[i];
    ss[i]='\0';
    k=1;
    while(k)
    {
        k=0;
    for(i=0;i<strlen(ss);i++)
    {
       if(ss[i]=='('&&ss[i+1]==')')
       {
           r=0;
          for(j=0;j<strlen(ss);j++)
          {
              if(j==i||j==i+1)
                continue;
              else
              {
                  ss[r]=ss[j];
                  r++;
              }
          }
          ss[r]='\0';
           k=1;
           break;
       }
    }
    if(strlen(ss)<2)
        break;
    }
    return strlen(ss);
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(()(()"; int Arg1 = 2; verify_case(0, Arg1, countCorrections(Arg0)); }
	void test_case_1() { string Arg0 = "()()(()"; int Arg1 = 1; verify_case(1, Arg1, countCorrections(Arg0)); }
	void test_case_2() { string Arg0 = "(())(()())"; int Arg1 = 0; verify_case(2, Arg1, countCorrections(Arg0)); }
	void test_case_3() { string Arg0 = "())(())((()))))()((())))()())())())()()()"; int Arg1 = 7; verify_case(3, Arg1, countCorrections(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
MissingParentheses ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
