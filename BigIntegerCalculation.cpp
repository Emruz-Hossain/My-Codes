#include"math.h"
#include"stdio.h"
#include"string.h"
#include<cstring>
#include<string>
#include<algorithm>
#include"iostream"
using namespace std;

char tm;
string Sum(string a,string b);
void Substrct(string a,string b);
string Multiply(string a,string b);
void Factorial(int n);
void Power(string N,int p);

string Sum(string a,string b)
{
    int i,j,k,t,h,l1=a.size(),l2=b.size();
    string sum;
    for(sum="",i=l1-1,j=l2-1,h=k=0;i>=0&&j>=0;i--,j--)
    {
        t=a[i]+b[j]-2*48+h;
        sum+=(t%10+48);
        h=t/10;
    }
    while(i>=0)
    {
        t=a[i]-48+h;
        sum+=(t%10+48);
        h=t/10;
        i--;
    }
    while(j>=0)
    {
        t=b[j]-48+h;
        sum+=(t%10+48);
        h=t/10;
        j--;
    }
    if(h) sum+=(h+48);
    reverse(sum.begin(),sum.end());
    return sum;
}
void Substrct(string a,string b)
{
    int i,j,k,t,ch,A,B,l1=a.size(),l2=b.size(),cmp;
    string T,sum;
    cout<<"Result is ";
    if(l1==l2) cmp=a.compare(b);
    else cmp=(l1<l2)?-1:1;
    if(cmp<0)
    {
        T=a,a=b,b=T;
        cout<<'-',t=l1,l1=l2,l2=t;
    }
    for(i=l1-1,j=l2-1,ch=0;i>=0&&j>=0;i--,j--)
    {
        A=a.at(i)-48,B=b.at(j)-48+ch;
        if(A>=B) ch=0,sum+=(A-B+48);
        else ch=1,t=10+A,sum+=(t-B+48);
    }
    while(i>=0)
    {
        A=a.at(i)-48,B=ch,i--;
        if(A>=B) ch=0,sum+=(A-B+48);
        else ch=1,t=10+A,sum+=(t-B+48);
    }
    for(j=0,k=sum.size()-1;(!(sum.at(k)-48)&&k>0);k--,j++);
    sum.erase(k+1,j);
    reverse(sum.begin(),sum.end());
    cout<<sum<<endl;
    return;
}
string Multiply(string a,string b)
{
    int i,j,k,t,h,A,B,cnt,l;
    string sum,T;
    int l1=a.size(),l2=b.size();
    for(i=l1-1,cnt=0;i>=0;i--)
    {
        A=a.at(i)-48;
        T="";
        for(k=0;k<cnt;k++)
            T+='0';
        for(j=l2-1,h=0;j>=0;j--)
        {
            B=b.at(j)-48;
            t=A*B+h;
            tm=(t%10+48);
            T+=tm;
            h=t/10;
        }
        if(h) tm=h+48,T+=tm;
        for(l=0,k=T.size()-1;l<=(k-1)/2;l++)
        {
            tm=T[l];
            T[l]=T[k-l];
            T[k-l]=tm;
        }
        sum=Sum(T,sum);
        cnt++;
    }
    return sum;
}
void Factorial(int n)
{
    int a;
    char tm;
    string N,res;
    for(a=n;a;tm=(a%10+48),res+=tm,a/=10);
    reverse(res.begin(),res.end());
    for(n--;n;n--)
    {
        for(N="",a=n;a;a/=10)
        {
            N+=(a%10+48);
        }
        reverse(N.begin(),N.end());
        res=Multiply(res,N);
    }
    cout<<"Result is "<<res<<endl;
    return;
}
void Power(string N,int p)
{
    string res=N;
    --p;
    while(p--)
    {
        res=Multiply(res,N);
    }
    cout<<"Result is "<<res<<endl;
    return;
}

int main()
{
    int ch,n,p;
    string a,b;
    printf("%13c__________WELCOME TO BIG INTEGER CALCULATION__________\n",' ');
    printf("\n\nHere are five methods on Big Integer calculation like as the followings.\nI can select anyone of them or '0' to exit\n");
    printf("\n01. Summation ( a + b )\n");
    printf("\n02. Substraction ( a - b )\n");
    printf("\n03. Multiplication ( a * b )\n");
    printf("\n04. Factorial ( n! )\n");
    printf("\n05. Power ( b^p )\n");
    printf("\nFor exit press 0\n");
    printf("\nEnter your choise: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:cin>>a>>b;
            cout<<"Result is "<<Sum(a,b)<<endl;
            break;
        case 2:cin>>a>>b;
            Substrct(a,b);
            break;
        case 3:cin>>a>>b;
            cout<<"Result is "<<Multiply(a,b)<<endl;
            break;
        case 4:cin>>n;
            Factorial(n);
            break;
        case 5:cin>>b>>p;
            Power(b,p);
            break;
        case 0:return 0;
    }
    return main();
}
//Sample Input:
//1
//36457605496874303546164
//345360638643210034760347984054
//2
//364532412341235235213
//53643320354042135645736308
//3
//3646432784343242344234324
//32432432423423476573654675653
//4
//111
//5
//505
//100
//0
//Sample Output:
//Result is 345360675100815531634651530218
//Result is -53642955821629794410501095
//Result is 118262684864768118627667571894942410194340508849713572
//Result is 1762952551090244663872161047107075788761409536026565516041574063347346955087248316436555574598462315773196047662837978913145847497199871623320096254145331200000000000000000000000000
//Result is 2133721885931776488158936331451186927873627279254131785599430975264983767989383237637198211501204851693742852683520235974210361419227804211468758818972525651889824539903589597046675374432468522387347998430678267672179693881709242921085323274610345833934843540191650390625
