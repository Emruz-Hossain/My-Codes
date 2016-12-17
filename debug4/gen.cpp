#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("xinput.txt","w",stdout);
    printf("500000 1000000000\n");
    for(int i=0;i<500000;i++)
        printf("%d ",rand()%1000000000);
    printf("\n");
}
