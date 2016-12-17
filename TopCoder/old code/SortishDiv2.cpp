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

struct SortishDiv2{
    int ar[1000],k,visit[200],pos[200],trg,d,n,ans;
    vector<int>v;
    int check(void)
    {
        int i,j,cnt;
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[i]<ar[j])
                cnt++;
            }
        }
        if(cnt==trg)
            return 1;
        else
            return 0;
    }
void rec(int ind)
{
    int i,r;
    if(ind>=v.size())
    {
        r=check();
        if(r==1)
            ans++;
    }
    for(i=0;i<d;i++)
    {
        if(visit[pos[i]]==0)
        {
            visit[pos[i]]=1;
            ar[pos[i]]=v[ind];
            rec(ind+1);
            visit[pos[i]]=0;
        }
    }
}
int ways(int sortedness, vector <int> seq)
{
    int ret,i,j,p;
    trg=sortedness;
    ans=0;d=0;
    v.clear();
    n=seq.size();
    for(i=1;i<=n;i++)
    {
        p=0;
        for(j=0;j<n;j++)
        {
            if(seq[j]==i)
            {
                p=1;
                break;
            }
        }
        if(p==0)
        {
            v.push_back(i);
        }

    }
    for(i=0;i<n;i++)
    {
        ar[i]=seq[i];
        if(seq[i]==0)
            pos[d++]=i;
    }

        memset(visit,0,sizeof(visit));
     rec(0);
    return ret=ans;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {4, 0, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, ways(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, ways(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, ways(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 2, 0, 5, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, ways(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
SortishDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
