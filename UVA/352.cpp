#include<stdio.h>
#include<string.h>
using namespace std;
char str[100][100];
int C[]={1,-1,0,0,-1,1,1,-1};
int R[]={0,0,1,-1,-1,-1,1,1};
void dfs(int x,int y,int p)
{

    int i,m,n;
    str[x][y]='0';
    for(i=0;i<8;i++)
    {
        m=x+R[i];
        n=y+C[i];
        if(m>=0&&n>=0&&m<p&&n<p&&str[m][n]!='0')
            {

                dfs(m,n,p);
            }
    }
}
int main()
{
    int m,i,c=0,j,t=0;
    while(scanf("%d",&m)==1)
    {
        t++;
        c=0;
        memset(str,0,sizeof(str));
        for(i=0;i<m;i++)
            scanf("%s",&str[i]);
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(str[i][j]!='0')
                {
                    dfs(i,j,m);
                    c++;
                }
            }

        }
        printf("Image number %d contains %d war eagles.\n",t,c);
    }
    return 0;
}
