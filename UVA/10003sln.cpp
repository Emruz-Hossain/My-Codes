// Headers, etc...

#define in cin

using namespace std;
#include<stdio.h>
#include<iostream>
#include<vector>
vector<int> CutSpots;
int length, cuts;
vector< vector<int> > memo;
int MV = 1<<15;

int BestWay(int a, int b)
{
   if(memo[a][b] != -1)
      return memo[a][b];

   if(b-a == 1)
      return memo[a][b] = 0;

   int minv = MV;
   for(int i = a+1; i < b; ++i)
   {
      //cut here
      minv = min(minv, (CutSpots[i]-CutSpots[a]) + (CutSpots[b]-CutSpots[i])
                    + BestWay(a,i) + BestWay(i, b) );

   }
   return memo[a][b] = minv;
}



int main()
{
   //ifstream in("in.txt");
      while(1)
      {
         in >> length;
         if(length == 0)
            break;

         in >> cuts;

         CutSpots = vector<int>(cuts);

         CutSpots.push_back(0);

         //given in increasing order
         for(int i = 0; i < cuts; ++i)
            in >> CutSpots[i+1];

         CutSpots.push_back(length);

         memo = vector< vector<int> >(cuts+2, vector<int>(cuts+2,-1));

         cout << "The minimum cutting is " << BestWay(0, cuts+1) << "." << endl;
      }
      return 0;
}


