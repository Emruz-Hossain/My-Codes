#include<stdio.h>
#include<string.h>
char str[500][500];
int R[]={1,-1,0,0,1,1,-1,-1};
int C[]={0,0,1,-1,1,-1,1,-1};
void dfs(int x,int y,int m,int n)
{
    int i,p,q;
    if(str[x][y]!='@')
        return;
    str[x][y]='*';
    for(i=0;i<8;i++)
    {
        p=x+R[i];
        q=y+C[i];
        if(p>=0&&q>=0&&p<m&&q<n&&str[p][q]=='@')
        {
            dfs(p,q,m,n);
        }
    }
}
int main()
{
    int i,j,c,m,n;
    while(1)
    {
        c=0;
        scanf("%d %d",&m,&n);
        if(m==0)
            break;
        else
        {
            for(i=0;i<m;i++)
                scanf("%s",&str[i]);

            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(str[i][j]=='@')
                    {
                        dfs(i,j,m,n);
                        c++;
                    }
                }
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
