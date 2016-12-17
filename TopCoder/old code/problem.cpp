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
    int rem,lim;
};

struct SlimeXSlimonadeTycoon{
int sell(vector <int> morning, vector <int> customers, int stale_limit)
{
    int ret=0,i,j,k,total=0,x;
    st ar[100];
    memset(ar,0,sizeof(ar));
    for(i=0;i<morning.size();i++)
    {
        ar[i].rem=morning[i];
        ar[i].lim=stale_limit;
        total=0;
        for(j=0;j<=i;j++)
        {
            if(ar[j].rem!=0&&ar[j].lim>0)
            {
                total+=ar[j].rem;
            }
        }
        if(customers[i]>=total)
        {
            ret+=total;
            for(k=0;k<=i;k++)
            {
                if(ar[k].rem!=0&&ar[k].lim>0)
                    ar[k].rem=0;ar[k].lim=0;
            }
        }
        else
        {
            ret+=customers[i];
             x=total-customers[i];
            k=0;
            while(x>0)
            {
                if(ar[k].rem!=0&&ar[k].lim>0)
                {
                    if(ar[k].rem>=x)
                    {
                         ar[k].rem=x;
                         x=0;
                    }

                    else
                    {

                        x=x-ar[k].rem;
                        ar[k].rem=0;
                    }

                }
                k++;
            }
        }
        for(j=0;j<=i;j++)
            ar[j].lim--;


    }
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {{6430, 9856, 3755, 1132, 5044, 2910, 2913, 8683, 6779, 1189, 9497, 173, 764, 7747, 6464, 1326, 495, 2004, 3230, 1735, 2428, 8481, 9362, 8429, 9440, 5735, 5104, 9064, 5797, 9835, 4579, 5112, 8494, 9305, 8123, 8921, 9337, 8679, 3818, 2294, 3433, 672};  vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {597, 2911, 8701, 3753, 1205, 1617, 5207, 1568, 7720, 1225, 1634, 8220, 3522, 8959, 8426, 1918, 6154, 3811, 15, 7951, 9909, 5205, 9566, 271, 1505, 202, 6895, 8337, 6965, 496, 1537, 9123, 5641, 732, 4933, 8325, 9065, 7065, 7112, 3610, 7934, 7787}, 28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 40; verify_case(1, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 5, 5, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 15; verify_case(2, Arg3, sell(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10000, 0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8, 16, 32, 64}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 15; verify_case(3, Arg3, sell(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
SlimeXSlimonadeTycoon ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
