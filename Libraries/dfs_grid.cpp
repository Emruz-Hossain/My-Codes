//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#define S 105
char gd[S][S];
void dfs(int x,int y,int n,int m)
{
    int i,R[]={0,0,1,-1,-1,-1,1,1},C[]={1,-1,0,0,-1,1,-1,1};
    for(i=0;i<8;i++)
    {
        xx=x+R[i];
        yy=y+C[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&gd[xx][yy]=='@')
        {
            gd[xx][yy]='*';
            dfs(xx,yy,n,m);
        }
    }
}
int main()
{
    int n,m,i,j,cmp;
    while(scanf("%d%d",&n,&m)==2)
    {
        //getchar();
        for(i=0;i<n;i++)
        scanf("%s",gd[i]);//gets(gd[i]);
        for(i=cmp=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(gd[i][j]=='@')
                {
                    dfs(i,j,n,m);
                    cmp++;
                }
            }
        }
        printf("%d\n",cmp);
    }
    return 0;
}

