//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#define S 105
char s[S],ss[S];
int dp[S][S];
int Max(int a,int b)
{
	return a>b?a:b;
}
void path(int r,int c)
{
	if(r<=0||c<=0)
	return;
	if(dp[r][c]>dp[r-1][c-1]&&s[r-1]==ss[c-1])
	{
		path(r-1,c-1);
		printf("%c",s[r-1]);
	}
	else if(dp[r-1][c]>dp[r][c-1])
	path(r-1,c);
	else
	path(r,c-1);
}
int main()
{
	int i,j,l,ll;
	while(scanf("%s%s",s,ss))
	{
		l=strlen(s);
		ll=strlen(ss);
		for(i=1;i<=l||i<=ll;i++)
		dp[i][0]=0,dp[0][i]=0;
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=ll;j++)
			{
				if(s[i-1]==ss[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
				else
				dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[l][ll]);
		path(l,ll);
		printf("\n");
	}
	return 0;
}
