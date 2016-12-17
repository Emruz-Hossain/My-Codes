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
 struct st
    {
        long long len,pos;
    }ar[300];

bool cmp(st a,st b)
    {
        return (a.pos<b.pos);
    }
struct ConnectingCars{

long long minimizeCost(vector <int> positions, vector <int> lengths)
{
    long long ret,br[300],nc1,nc2,i,a,b,sm,sm1,sm2,ind1,ind2;
    for(i=0;i<positions.size();i++)
    {
        ar[i].len=lengths[i];
        ar[i].pos=positions[i];
    }
    long long n=positions.size();
    sort(ar,ar+n,cmp);
    for(i=0;i<positions.size();i++)
    {
        br[i]=ar[i].pos+ar[i].len;
    }
    nc1=1;
    nc2=1;
    a=br[0];
    ind1=1;
    ind2=n-2;
    b=ar[n-1].pos;
    sm=0;
    while(a<b)
    {
        sm1=(ar[ind1].pos-br[ind1-1])*nc1;
        sm2=(ar[ind2+1].pos-br[ind2])*nc2;
        if(sm1<sm2)
        {

            sm+=sm1;
            nc1++;
            a=br[ind1];
            ind1++;
        }
        else
        {
            sm+=sm2;
            nc2++;
            b=ar[ind2].pos;
            ind2--;
        }
    }
    return ret=sm;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 5, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 15LL; verify_case(0, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 50, 1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 96LL; verify_case(1, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 10, 100, 13, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 3, 42, 40, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 66LL; verify_case(2, Arg2, minimizeCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5606451, 63581020, 81615191, 190991272, 352848147, 413795385, 468408016, 615921162, 760622952, 791438427}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42643329, 9909484, 58137134, 99547272, 39849232, 15146704, 144630245, 604149, 15591965, 107856540}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1009957100LL; verify_case(3, Arg2, minimizeCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ConnectingCars ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
