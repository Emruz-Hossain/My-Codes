#include<stdio.h>
#include<string.h>
int m,n,mat_a[100][100],mat_b[100][100],result[100][100];
void print()
{
    int i,j;
    printf("Result:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

void add()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            result[i][j]=mat_a[i][j]+mat_b[i][j];
        }
    }
    print();
}
void sub()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            result[i][j]=mat_a[i][j]-mat_b[i][j];
        }
    }
    print();
}
void mul()
{
    int i,j,k,r;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            r=0;
            for(k=0;k<n;k++)
            {
                r+=mat_a[i][k]*mat_b[k][j];
            }
            result[i][j]=r;
        }
    }
    printf("\nResult:\n");
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           printf("%d ",result[i][j]);
       }
       printf("\n");
   }
}
int main()
{
    int i,j,op,p=0,pp;
    while(1)
    {
        if(p>0)
        {
            printf("\nChose option:\n1.Continue\n2.Exit\n");
            scanf("%d",&pp);
            if(pp==2)
                break;
        }
        p=1;
        memset(mat_a,0,sizeof(mat_a));
        memset(mat_b,0,sizeof(mat_b));
        memset(result,0,sizeof(result));
    printf("Enter Dimension (m*n):\n");
    scanf("%d %d",&m,&n);
    printf("Enter matrix a:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat_a[i][j]);
        }
    }
    printf("Enter matrix b:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat_b[i][j]);
        }
    }
    printf("Chose an operation:\n1.Subtruction\n2.Addition\n3.Multiplication\n");
    scanf("%d",&op);
    if(op==1)
        sub();
    else if(op==2)
        add();
    else if(op==3)
        mul();
    }

}
