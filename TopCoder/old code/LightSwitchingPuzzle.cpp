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

struct LightSwitchingPuzzle{
int minFlips(string state)
{
    int ret,l,i,cnt,cyn,cny,visit[1005],p;
    l=state.size();
    cnt=0;
    for(i=1;i<=l;i++)
    {
        if(state[i-1]=='Y')
            visit[i]=1;
        else
            visit[i]=0;
    }
    for(i=2;i<=l;i++)
    {
        if(visit[i]==1)
        {
        p=1;
        while(p*i<=l)
        {
            visit[p*i]=0;
            p++;
        }
        cnt++;
        }
    }
    cyn=cnt;
   for(i=1;i<=l;i++)
    {
        if(state[i-1]=='Y')
            visit[i]=1;
        else
            visit[i]=0;
    }
    cnt=0;
    for(i=2;i<=l;i++)
    {
        if(visit[i]==0)
        {
        p=1;
        while(p*i<=l)
        {
            visit[p*i]=1;
            p++;
        }
        cnt++;
        }
    }
    cny=cnt;
    printf("%d %d\n",cyn,cny);
    if(state[0]=='Y')
    {
        ret=1+cny;
    }
    else
    {
        ret=min(cyn,2+cny);
    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNYNYNYNY"; int Arg1 = 2; verify_case(1, Arg1, minFlips(Arg0)); }
	void test_case_1() { string Arg0 = "YYYYYY"; int Arg1 = 1; verify_case(0, Arg1, minFlips(Arg0)); }
	void test_case_2() { string Arg0 = "NNNNNNNNNN"; int Arg1 = 0; verify_case(2, Arg1, minFlips(Arg0)); }
	void test_case_3() { string Arg0 = "YYYNYYYNYYYNYYNYYYYN"; int Arg1 = 4; verify_case(3, Arg1, minFlips(Arg0)); }
	void test_case_4() { string Arg0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"; int Arg1 = 12; verify_case(4, Arg1, minFlips(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
LightSwitchingPuzzle ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
