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

struct SRMCodingPhase{
int countScore(vector <int> points, vector <int> skills, int luck)
{
    int ret=0,d=0,rem=0,p=0,t;
    d=luck;
    t=skills[0]-d;
    if(t<=0)
        t=1;
    if(t<=75)
    ret=max(ret,points[0]-2*t);
    d=luck;
    t=skills[1]-d;
    if(t<=0)
        t=1;
    if(t<=75)
    ret=max(ret,points[1]-4*t);
    d=luck;
    t=skills[2]-d;
    if(t<=0)
        t=1;
    if(t<=75)
    ret=max(ret,points[2]-8*t);
    d=luck;
    if(skills[1]-d<=75)
    {
        if(skills[1]<=d)
        {
            p=points[1]-4;
            d=d-skills[1]+1;
            rem=75-1;
        }
        else
        {
            p=points[1]-4*(skills[1]-d);
            rem=75-skills[1]+d;
             d=0;
        }
    if(rem>=skills[0]-d)
    {
        if(skills[0]<=d)
        {
            p+=points[0]-2;
        }
        else
        {
            p+=points[0]-2*(skills[0]-d);
        }
    }
    }
    ret=max(ret,p);
    d=luck;
    if(skills[2]-d<=75)
    {
        if(skills[2]<=d)
        {
            p=points[2]-8;
            d=d-skills[2]+1;
            rem=75-1;
        }
        else
        {
            p=points[2]-8*(skills[2]-d);
            rem=75-skills[2]+d;
             d=0;
        }
    if(rem>=skills[0]-d)
    {
        if(skills[0]<=d)
        {
            p+=points[0]-2;
        }
        else
        {
            p+=points[0]-2*(skills[0]-d);
        }
    }
    }

    ret=max(ret,p);
    d=luck;
    if(skills[2]-d<=75)
    {
        if(skills[2]<=d)
        {
            p=points[2]-8;
            d=d-skills[2]+1;
            rem=75-1;
        }
        else
        {
            p=points[2]-8*(skills[2]-d);
            rem=75-skills[2]+d;
             d=0;
        }
    if(rem>=skills[1]-d)
    {
        if(skills[1]<=d)
        {
            p+=points[1]-4;
        }
        else
        {
            p+=points[1]-4*(skills[1]-d);
        }
    }
    }
     ret=max(ret,p);
     d=luck;
    if(skills[2]-d<=75)
    {
        if(skills[2]<=d)
        {
            p=points[2]-8;
            d=d-skills[2]+1;
            rem=75-1;
        }
        else
        {
            p=points[2]-8*(skills[2]-d);
            rem=75-skills[2]+d;
             d=0;
        }
    if(rem>=skills[1]-d)
    {
        if(skills[1]<=d)
        {
            p+=points[1]-4;
            d=d-skills[1]+1;
            rem=rem-1;
        }
        else
        {
            p+=points[1]-4*(skills[1]-d);
            rem=rem-skills[1]+d;
            d=0;
        }
    if(rem>=skills[0]-d)
    {
        if(skills[0]<=d)
        {
            p+=points[0]-2;
        }
        else
        {
            p+=points[0]-2*(skills[0]-d);
        }
    }
    }
    }
    ret=max(ret,p);
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {282, 501, 910}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 15, 97}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 59; int Arg3 = 1047; verify_case(0, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {300, 600, 900}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 65, 90}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 680; verify_case(1, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {250, 550, 950}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 25, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 75; int Arg3 = 1736; verify_case(2, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {256, 512, 1024}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {35, 30, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1216; verify_case(3, Arg3, countScore(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {300, 600, 1100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {80, 90, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 0; verify_case(4, Arg3, countScore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
SRMCodingPhase ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
