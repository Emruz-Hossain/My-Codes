//MD: EMRUZ HOSSAIN
//CSE 12 SEC:B
//ID: 1204084
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int ar[1000005],Temp[1000005];
long long cnt;
void marge(int st,int m,int mm,int end)
{
    int i1=st,j1=mm,i;
    for(i=st;i<=end;i++)
    {
        if(ar[i1]<=ar[j1]&&i1<=m)
        {
             Temp[i]=ar[i1];
             i1++;
        }
        else if(ar[i1]>ar[j1]&&i1<=m&&j1<=end)
        {
            cnt+=(m-i1+1);
            Temp[i]=ar[j1];
            j1++;
        }
        else if(i1>m)
        {
            Temp[i]=ar[j1];
            j1++;
        }
        else if(j1>end)
        {
            Temp[i]=ar[i1];
            i1++;
        }
    }
    for(i=st;i<=end;i++)
    {
        ar[i]=Temp[i];
    }
}
void divide(int st,int end)
{
    int m;
    if(end-st<=0)
    return;
        m=(end+st)/2;
        divide(st,m);
        divide(m+1,end);
        marge(st,m,m+1,end);

}
int main()
{
    int i,j,n;
    cnt=0;
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    divide(0,n-1);
    printf("%lld\n",cnt);
}
