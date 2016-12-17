#include<stdio.h>
#include<string.h>
#define inf 1<<30
#define max 10005
int cl[]={-1,1,0,0};
int rw[]={0,0,-1,1};
int ar[max][max];
void rec(int x,int y,int m,int R,int C)
{
    int p,q,i;
    if(ar[x][y]>m)
    {
         ar[x][y]=m;
         m++;
    }
    for(i=0;i<4;i++)
    {
        p=rw[i]+x;
        q=cl[i]+y;
        if(p>=0&&q>=0&&p<R&&q<C&&ar[p][q]>m+1)
        {
            rec(p,q,m,R,C);
        }
    }
}
int main()
{
    int R,C,r,sr,sc,dr,dc,i,m,j,c,k,n;
    while(1)
    {
        scanf("%d %d",&R,&C);
        if(R==0&&C==0)
            break;
        for(i=0;i<=R;i++)
        {
            for(j=0;j<=C;j++)
                ar[i][j]=inf;
        }
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            scanf("%d %d",&r,&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&c);
                ar[r][c]=-1;
            }
        }
        scanf("%d %d %d %d",&sr,&sc,&dr,&dc);
        rec(sr,sc,0,R,C);
        printf("%d\n",ar[dr][dc]);
    }
    return 0;
}
