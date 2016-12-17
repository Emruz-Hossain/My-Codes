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

struct TheKingsArmyDiv2{
int getNumber(vector <string> state)
{
    int ret=0,i,j,p=0,q=0,r=0,s=0,flg=0,cl,rl;
    rl=state.size();
    cl=state[0].size();
    for(i=0;i<rl;i++)
    {
        for(j=0;j<cl;j++)
        {
            if(state[i][j]=='H')
            {
                //out<<i<<" "<<j<<" "<<state[i]<<endl;
                flg=1;
                if(i-1>=0&&state[i-1][j]=='H')
                p=1;
                if(j-1>=0&&state[i][j-1]=='H')
                q=1;
                if(i+1<rl&&state[i+1][j]=='H')
                r=1;
                if(j+1<cl&&state[i][j+1]=='H')
                s=1;
                //cout<<state[i][j+1]<<endl;

            }

        }
    }
   // printf("%d %d %d %d\n",p,q,r,s);
    if(p||q||s||r)
        return ret=0;
    else if(flg==1)
        return ret=1;
    else
    return ret=2;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSSSS",
 "SSHHS",
 "SSSSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"SSSSS",
 "SSHSH",
 "HSSSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"SSS",
 "SSS",
 "SSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"HSHSHSH", "SSSHSSS", "SSHSHSS", "SHSHSHS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"HHSH", "HHHS", "HSSS", "SHSH", "HHHS", "HSHH", "SSSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
TheKingsArmyDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
