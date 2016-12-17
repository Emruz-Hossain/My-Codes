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
#include<iomanip>
#include<ctime>
using namespace std;
struct st
{
    int n;
    char ss[20];
}mp[10];
int ar[15];
bool cmp(st a,st b)
{
    if(a.n<b.n)
        return true;
    else if(a.n>b.n)
        return false;
    else
    {
        if(strcmp(a.ss,b.ss)<0)
            return true;
        else
            return false;
    }
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
        while(scanf("%d %d %d %d %d %d %d %d %d",&ar[1],&ar[2],&ar[3],&ar[4],&ar[5],&ar[6],&ar[7],&ar[8],&ar[9])==9)
        {
            strcpy(mp[0].ss,"BCG");
            mp[0].n=ar[4]+ar[7]+ar[3]+ar[9]+ar[2]+ar[5];
            strcpy(mp[1].ss,"BGC");
            mp[1].n=ar[4]+ar[7]+ar[3]+ar[8]+ar[2]+ar[6];
            strcpy(mp[2].ss,"CBG");
            mp[2].n=ar[6]+ar[9]+ar[1]+ar[7]+ar[2]+ar[5];
            strcpy(mp[3].ss,"CGB");
            mp[3].n=ar[1]+ar[2]+ar[4]+ar[6]+ar[8]+ar[9];
            strcpy(mp[4].ss,"GBC");
            mp[4].n=ar[1]+ar[3]+ar[5]+ar[6]+ar[7]+ar[8];
            strcpy(mp[5].ss,"GCB");
            mp[5].n=ar[1]+ar[3]+ar[4]+ar[5]+ar[8]+ar[9];
            sort(mp,mp+6,cmp);
            printf("%s %d\n",mp[0].ss,mp[0].n);
        }

    return 0;
}
