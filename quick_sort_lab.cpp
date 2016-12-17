#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int ar[100005];
int scanLeft(int pvt,int lft,int srht);
int scanRight(int pvt,int rght,int sleft);
int scanLeft(int pvt,int lft,int srht)
{
    int i,tmp;
    for(i=lft;i<pvt;i++)
    {
        if(ar[i]>ar[pvt])
        {
            tmp=ar[pvt];
            ar[pvt]=ar[i];
            ar[i]=tmp;
            srht=i+1;
            return scanRight(i,pvt,srht);
        }
    }
    return pvt;
}
int scanRight(int pvt,int rght,int sleft)
{
    int i,tmp;
    for(i=rght;i>pvt;i--)
    {
        if(ar[i]<ar[pvt])
        {
            tmp=ar[pvt];
            ar[pvt]=ar[i];
            ar[i]=tmp;
            return scanLeft(i,sleft,pvt);
        }
    }
   return pvt;
}
int rec(int lft,int rht)
{
    int comp=0,p,q,pos,mid,r;
    if(lft>=rht)
         return 0;
    comp=rht-lft;
    mid=(comp+1)/2;
    if(ar[lft]>rht)
    pos=scanRight(mid,rht,lft);
    p=rec(lft,pos-1);
    q=rec(pos+1,rht);
    return comp+p+q;
}
int main()
{
    int n,i;
    //freopen("Prob04.txt","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("Number Of Comparism: %d\n",rec(0,n-1));
}
