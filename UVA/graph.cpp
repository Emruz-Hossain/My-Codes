#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,c,i,t,c1,c2,m;
    int ar[100000]={0};
    scanf("%d %d",&n,&c);
    for(i=0;i<c;i++)
    {
        scanf("%d %d",&c1,&c2);
        if(i==0)
        {
            ar[c1]=1;
            ar[c2]=ar[c1];
        }
        else
        {
            if(ar[c1]==0&&ar[c2]==0)
            {
                ar[c1]=i+2;
                ar[c2]=ar[c1];
            }
            else if(ar[c1]!=0&&ar[c2]==0)
            {
                ar[c2]=ar[c1];
            }
            else if(ar[c1]==0&&ar[c2]!=0)
                ar[c1]=ar[c2];

        }

    }
    sort(ar,ar+n);
    if(c==0)
        t=n;
    else
    {
    t=0;
    m=-1;
    for(i=1;i<=n;i++)
    {
        if(ar[i]!=m)
        {
            t++;
            m=ar[i];
        }

    }
    }
    #include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,c,i,t,c1,c2,m;
    int ar[100000]={0};
    scanf("%d %d",&n,&c);
    for(i=0;i<c;i++)
    {
        scanf("%d %d",&c1,&c2);
        if(i==0)
        {
            ar[c1]=1;
            ar[c2]=ar[c1];
        }
        else
        {
            if(ar[c1]==0&&ar[c2]==0)
            {
                ar[c1]=i+2;
                ar[c2]=ar[c1];
            }
            else if(ar[c1]!=0&&ar[c2]==0)
            {
                ar[c2]=ar[c1];
            }
            else if(ar[c1]==0&&ar[c2]!=0)
                ar[c1]=ar[c2];

        }

    }
    sort(ar,ar+n);
    t=0;
    m=-1;
    for(i=0;i<n;i++)
    {
        if(ar[i]!=m)
        {
            t++;
            m=ar[i];
        }

    }
    printf("%d",t);
    return 0;
}
//10 9
//1 2
//3 4
//5 6
//7 8
//9 10
//1 10
//9 7
//8 5
//6 4
    printf("%d",t);
    return 0;
}
x
