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

struct RunningAroundPark{
int numberOfLap(int N, vector <int> d)
{
    int ret=1,i;
    for(i=1;i<d.size();i++)
    {
        if(d[i]<=d[i-1])
            ret++;
    }
    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
