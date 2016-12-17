#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
struct st
{
    int A,B,C;
}Allocated[10],Max[10],Need[10];
vector<int>v,Safe;
int n,AvailA,AvailB,AvailC;
int visit[10];
int Check(void)
{
  int Ava=AvailA,Avb=AvailB,Avc=AvailC;
  for(int i=0;i<n;i++)
  {
      int p=v[i];
      if(Need[p].A<=Ava&&Need[p].B<=Avb&&Need[p].C<=Avc)
      {
          Ava+=Allocated[p].A;
          Avb+=Allocated[p].B;
          Avc+=Allocated[p].C;
      }
      else
        return 0;
  }
  return 1;
}
void Gen(int idx)
{
    if(v.size()==n)
    {
        if(Check())
        {
           if(Safe.size()==0)
            Safe=v;
            return;
        }
        return;

    }
    int limit=n;
    for(int i=idx;i<limit;i++)
    {
        if(visit[i]==0)
        {
            v.push_back(i);
            visit[i]=1;
            Gen(i);
            v.pop_back();
            visit[i]=0;
        }
        if(i==n-1)
        {
             i=-1;
             limit=idx;
        }

    }
}
int main()
{
    int i;
    pf("Enter Number of Process: ");
    sf("%d",&n);
    pf("Enter Allocated matrix:\n");
    for(i=0;i<n;i++)
    {
        sf("%d %d %d",&Allocated[i].A,&Allocated[i].B,&Allocated[i].C);
    }
    pf("Enter Max matrix:\n");
    for(i=0;i<n;i++)
    {
        sf("%d %d %d",&Max[i].A,&Max[i].B,&Max[i].C);
    }
    pf("Enter Available Resources:\n");
    sf("%d %d %d",&AvailA,&AvailB,&AvailC);
    for(i=0;i<n;i++)
    {
        Need[i].A=Max[i].A-Allocated[i].A;
        Need[i].B=Max[i].B-Allocated[i].B;
        Need[i].C=Max[i].C-Allocated[i].C;
    }
    v.clear();
    Safe.clear();
    Gen(0);
    if(Safe.size()==0)
    {
        pf("Deadlock.\n");
    }
    else
    {
        pf("Safe Secuence:\n< ");
        for(i=0;i<Safe.size();i++)
            pf("P%d ",Safe[i]);
        pf(">\n");
    }

}
//5
//0 1 0
//2 0 0
//3 0 2
//2 1 1
//0 0 2
//
//7 5 3
//3 2 2
//9 0 2
//2 2 2
//4 3 3
//
//3 3 2
