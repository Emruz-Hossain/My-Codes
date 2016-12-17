#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[1050],i,n,t,j,c,b[1025];
    scanf("%d",&t);
    for(i=1;i<=1000;i++)
    {
        c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
                c++;
        }
        a[i]=c;
        b[i]=c;
    }
    sort(a,a+1000);
    for(i=1;i<=1000;i++)
        printf("%d %d---",a[i],b[i]);
    return 0;
}
