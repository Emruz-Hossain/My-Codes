#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int POW(int a,int p)
{
    int sm=1;
    for(int i=1;i<=p;i++)
        sm=sm*a;
    return sm;
}
int main()
{
    int t,a,s,n,m,c;
    scanf("%d",&t);

    while(t--){
    s=0;c=0;
        scanf("%d",&n);
        m=n;
        while(n!=0){
            n/=10;
            c++;
        }
    while(m!=0){
                a=m%10;
                cout<<pow(a,c)<<endl;
              //cout<<pow(a,c)<<endl;
              printf("%d ",s);
                s=s+POW(a,c);
                printf("%d\n",s);
                m/=10;
    }
         printf("%d\n",s);

    }
    return 0;
}
