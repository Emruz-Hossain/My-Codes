#include<bits/stdc++.h>
using namespace std;
char ss[10005];
int plndrm[1005][1005],ln,dp[1005];
int chk(int i,int j)
{
	if(i==j)
		return plndrm[i][j]=1;
	if(i>j)
		return 0;
	if(plndrm[i][j]!=-1)
		return plndrm[i][j];
	 if(ss[i]==ss[j])
	 {
	     if(j-i==1)
            plndrm[i][j]=1;
         else
	 	plndrm[i][j]=chk(i+1,j-1);
	 }
	 if(plndrm[i][j]<1)
	 {
	 	plndrm[i][j]=0;
	 }
	 chk(i+1,j);
	 chk(i,j-1);
	 return plndrm[i][j];
}
int main()
{
	int l,i,j,ans=0,t,x;
	scanf("%d",&t);
  for(x=1;x<=t;x++)
    {
	scanf("%s",&ss);
	ln=l=strlen(ss);
	memset(plndrm,-1,sizeof(plndrm));
	chk(0,l-1);
	for(i=0;i<l;i++)
        dp[i]=999999;
	for(i=0;i<l;i++)
    {
        if(plndrm[0][i]==1)
            dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(plndrm[j+1][i]==1)
            {
                if(dp[i]>dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
    }
	printf("Case %d: %d\n",x,dp[l-1]);
    }
}
