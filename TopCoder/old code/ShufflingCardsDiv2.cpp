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

struct ShufflingCardsDiv2{
string shuffle(vector <int> permutation)
{
    string ret;
    int n,i,j,k,p;
    vector<int>v1,v2;
    for(i=0;i<permutation.size();i++)
    {
        if(i%2==0)
        {
           v1.push_back(permutation[i]);
        }
        else
        {
            v2.push_back(permutation[i]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    permutation.clear();
    p=0;
    for(i=0,j=0;i<permutation.size()/2||j<permutation.size()/2;)
    {
        if(p==0)
        {
             permutation.push_back(v1[i]);
             p=1;
             i++;
        }
        else
        {
            permutation.push_back(v2[j]);
            p=0;
            j++;
        }

    }
    v1.clear();
    v2.clear();
    for(i=0;i<permutation.size();i++)
    {
        if(i%2==0)
        {
           v1.push_back(permutation[i]);
        }
        else
        {
            v2.push_back(permutation[i]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    permutation.clear();
    p=0;
    for(i=0,j=0;i<permutation.size()/2||j<permutation.size()/2;)
    {
        if(p==0)
        {
             permutation.push_back(v1[i]);
             p=1;
             i++;
        }
        else
        {
            permutation.push_back(v2[j]);
            p=0;
            j++;
        }

    }
    for(i=1;i<=permutation.size();i++)
    {
        if(permutation[i-1]!=i)
            return  "Impossible";
    }
    return ret="Possible";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {1,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {1,4,2,5,3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {8,5,4,9,1,7,6,10,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(4, Arg1, shuffle(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ShufflingCardsDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
