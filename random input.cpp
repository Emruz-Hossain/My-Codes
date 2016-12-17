#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    freopen("input.txt","w",stdout);
    srand(time(NULL));
    int n,k,q;
    for(int i=0;i<100;i++)
    {
        n=(rand()%1000000000)+1;
        k=(rand()%1000000000)+1;
        q=(rand()%n)+1;
        printf("%d %d %d\n",n,k,q);
    }
    return 0;
}
