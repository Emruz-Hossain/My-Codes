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
char ss[500][500];
int R[]={1,-1,0,0};
int C[]={0,0,-1,1};
int ct,visit[200][200],m,n,v[200];
map<char,int>mp;
void color(int x,int y,char ch)
{
    int i,p,q;
    if(visit[x][y]==1)
        return;
    visit[x][y]=1;
    ct++;
    for(i=0;i<4;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&p<m&&q>=0&&q<n&&ss[p][q]==ch&&visit[p][q]==0)
        {

            color(p,q,ch);
        }
    }
}
struct ConnectingGameDiv2{
int getmin(vector <string> board)
{
    int sm=1<<28,i,j,p;
    m=board.size();
    n=board[0].size();
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            ss[i][j]=board[i][j];
        }
    }
    memset(visit,0,sizeof(visit));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(visit[i][j]==0)
            {
                ct=0;
                color(i,j,ss[i][j]);
                mp[ss[i][j]]=ct;
                //printf("%d\n",ct);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        memset(v,0,sizeof(v));
        p=0;
        for(j=0;j<n;j++)
        {
            if(v[ss[i][j]]==0&&v[ss[i-1][j]]==0)
            {
                v[ss[i][j]]=1;
                p+=mp[ss[i][j]];
            }
        }
        sm=min(p,sm);
    }
    //printf("%d\n",sm);
    return sm;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA"
,"BC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAB"
,"ACD"
,"CCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {"iii"
,"iwi"
,"iii"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"qKKKK", "qKKKK", "qKKKK", "KKKKK", "KKKKK", "KKKKK", "KKKKK", "eKKKK", "eKKKK", "eK7MM", "EE7MM", "EEEMM", "8EEOO", "SEEOT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {"yyAArJqjWTH5","yyEEruYYWTHG","hooEvutpkkb2","OooNgFFF9sbi","RRMNgFL99Vmm","R76XgFF9dVVV","SKnZUPf88Vee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ConnectingGameDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
