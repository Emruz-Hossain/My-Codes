#include<stdio.h>
#include<string.h>
#define sf scanf
#define pf printf
char str[100],ar[100];
int visit[100];
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,l,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    sort(ar,ar+n);
    do
    {
        for(i=0;i<n;i++)
            printf("%d ",ar[i]);
        printf("\n");
    }while(next_permutation(ar,ar+n));
    return 0;
}
