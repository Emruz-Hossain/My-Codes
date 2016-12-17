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
char ss[5][500];
int visit[5][500];
int mx,l;
void rec(int x,int y,int pt)
{
    while(1)
    {
        if(y>=l-1)
            break;
        if(ss[x][y+1]=='.')
        {
           y=y+1;
           pt++;
        }
        else
        {
            if(x==0)
                x=1;
            else
                x=0;
            pt++;
        }
    }
    mx=min(mx,pt);
}
struct PathGameDiv2{
int calc(vector <string> board)
{
    int cnt,i;
    mx=1<<26;
    string ss1=board[0],ss2=board[1];
    cnt=0;
    l=ss1.length();

    for(i=0;i<ss1.length();i++)
    {
        ss[0][i]=ss1[i];
        if(ss[0][i]=='.')
            cnt++;
        ss[1][i]=ss2[i];
        if(ss[1][i]=='.')
            cnt++;
    }
    if(ss[0][0]=='.')
        rec(0,0,1);
    if(ss[1][0]=='.')
        rec(1,0,1);
    return cnt-mx;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...."
,"...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arr0[] = {"."
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arr0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
PathGameDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
