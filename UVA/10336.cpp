#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[5000][5000];
int ar[500],br[500];
int R[]={1,-1,0,0};
int C[]={0,0,1,-1};
void dfs(char c,int x,int y,int m,int n)
{
    int i,p,q;
    if(str[x][y]!=c)
        return;
    str[x][y]='0';
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<m&&q<n&&str[p][q]==c)
        {
            dfs(c,p,q,m,n);
        }
    }
}
int main()
{
    int i,j,c,m,n,t,k,p,l;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        c=0;
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
            scanf("%s",&str[i]);
    for(p='a';p<='z';p++)
    {
        c=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(str[i][j]==p)
                {
                    dfs(p,i,j,m,n);
                    c++;
                }
            }
        }
        ar[p]=c;
        br[p]=c;
    }
    sort(br,br+'z');
    printf("World #%d\n",k);
    for(i='z';i>='a';i--)
    {
        if(br[i]!=0)
        {
            for(j='a';j<='z';j++)
            {
                if(ar[j]==br[i])
               {
                   printf("%c: %d\n",j,br[i]);
                   ar[j]=0;
                   break;
               }
            }

        }

    }
    }
    return 0;
}
