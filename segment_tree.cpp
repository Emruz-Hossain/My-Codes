//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define inf 1<<25
#define sz 100005
#define eps 1e-9
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
 long long  arr[sz],br[sz];
#include <iostream>
#include <cmath>
#include<stdio.h>
using namespace std;

 long long getMid(long long s, long long e)
{
    return s + (e - s) / 2;
}
long long getSumUtil(long long *st, long long ss, long long se, long long qs, long long qe, long long index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return 0;
    long long mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * index + 1) +
           getSumUtil(st, mid+1, se, qs, qe, 2 * index + 2);
}

long long getSum(long long *st, long long n, long long qs, long long qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input"<<endl;
        return -1;
    }
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

// constructs Segment Tree for array[ss..se].
long long constructSTUtil(long long arr[], long long ss, long long se, long long *st, long long si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    long long mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
              constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

/* construct segment tree from given array.  */
long long *constructST(long long arr[], long long n)
{
    long long x = (long long)(ceil(log2(n)));
    long long max_size = 2 * (long long)pow(2, x) - 1;
    long long *st = new long long[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    long long n,i,l,r,q,tp ;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
         scanf("%I64d",&arr[i]);
         br[i]=arr[i];
    }
       sort(br,br+n);
    long long *st = constructST(arr, n);
    long long *bt= constructST(br, n);
    scanf("%I64d",&q);
    while(q--)
    {
         scanf("%I64d %I64d %I64d",&tp,&l,&r);
         if(tp==1)
         {
             printf("%I64d\n",getSum(st, n, l-1, r-1));
         }
         else
            printf("%I64d\n",getSum(bt,n,l-1,r-1));
    }

    return 0;
}
