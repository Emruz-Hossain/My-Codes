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
#define sz 2000
#define eps 1e-9
#define mod  1000000007
int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int t,x,i,n,k,c1,tp;
    double vl,avt,av1,total,tt1,res,wi,we,hn;
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    {
        c1=0;tt1=0.0;total=0.0,hn=0.0;
        scanf("%d",&n);
        k=n;
        while(k--)
        {
            scanf("%lf %d",&vl,&tp);
            total+=vl;
            if(tp==1)
            {
                tt1+=vl;
                c1++;
            }
        }
        avt=total/n;
        if(c1!=0)
        av1=tt1/c1;
        for(i=1;i<=n;i++)
        {
            hn+=1.0/i;
        }
        wi=hn*avt*n;
        if(c1==0)
        we=0;
        else
            we=(hn-1)*av1*c1;
        res=wi-we;
        printf("Case %d: %0.12lf\n",x,res);
    }


    return 0;
}



