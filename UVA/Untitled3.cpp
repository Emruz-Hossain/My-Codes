#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int ar[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&ar[i]);
    sort(ar,ar);

    for(i=0;i<10;i++)
        printf("%d ",ar[i]);
    return 0;
}
