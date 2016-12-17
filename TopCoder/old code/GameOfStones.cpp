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
 bool cmp(int a,int b)
    {
        return(a>b)?true:false;
    }
struct GameOfStones{

int count(vector <int> stones)
{
    int cnt,i,j,sum,d,p,n,ar[1000];
    sum=0;cnt=0;
    for(i=0;i<stones.size();i++)
    {
        sum+=stones[i];
    }
    n=stones.size();
    for(i=0;i<n;i++)
    {
        ar[i]=stones[i];
    }
    if(sum%n!=0)
        return -1;
    d=sum/n;
    sort(ar,ar+n,cmp);
   for(i=0;i<n;i++)
   {
       if(ar[i]==d)
        continue;
       else
       {
           p=ar[i]-d;
               if(p%2!=0)
                return -1;
           // printf("d=%d    p=%d n=%d\n",d,p,n);
           while(ar[i]!=d)
           {
           for(j=i+1;j<n;j++)
            {
                if(ar[j]<d)
                {
                    if((d-ar[j])%2!=0)
                        return -1;
                    else
                    {
                        ar[i]-=2;
                        ar[j]+=2;
                        cnt++;
                        break;
                    }

                }
            }
           }
       }


   }
   return cnt;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 15, 9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {10, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 8, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {10, 15, 20, 12, 1, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
GameOfStones ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
