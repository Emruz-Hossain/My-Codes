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

struct CatsOnTheLineDiv2{
    map<int ,int>mp;
string getAnswer(vector <int> position, vector <int> count, int time)
{
    int i,j,d;
    mp.clear();
    for(i=0;i<count.size();i++)
        mp[position[i]]=count[i];
    for(i=1000;i>=-1000;i--)
    {
            d=mp[i];
            mp[i]=0;
            j=i+time;
            if(i<0&&i+time>0)
                j++;
            while(d)
            {
                    if(mp[j]==0)
                    {
                        mp[j]=1;
                        d--;
                        j--;
                        if(i>0&&j<0&&j<i-time+1)
                            break;
                        else if(j<i-time)
                        {
                             break;
                        }

                    }
                    else
                    {
                        if(j<i)
                        {
                             mp[j]=mp[j]+1;
                             d--;
                        }
                        j--;
                        if(i>0&&j<0&&j<i-time+1)
                            break;
                        if(j<i-time)
                            break;
                    }
            }
            if(d>0)
                return "Impossible";
    }
    return "Possible";
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "Possible"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "Impossible"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {72, 31, -32, 90, -14, 52, 64, 25, 15, 91, 58, -16, 85, 36, -97, 46, 74, -4, -42, -92, -75, 28, 83, 69, -23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 18, 2, 25, 5, 0, 13, 19, 20, 26, 1, 25, 1, 21, 1, 21, 22, 6, 12, 21, 11, 9, 4, 14, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 52; string Arg3 = "Impossible"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
CatsOnTheLineDiv2 ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
