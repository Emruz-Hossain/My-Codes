//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
vector<string>V;
string ins,str,ss;
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l,mx,k,cnt;
    cin>>n;
    while(n--)
    {
        cin>>ins>>str;
        if(ins=="INSERT")
        {
            p=0;
            for(i=0;i<V.size();i++)
            {
                if(V[i]==str)
                {
                    cout<<"Already Exist"<<endl;
                    p=1;
                    break;
                }
            }
            if(p==0)
            {
                V.push_back(str);
                cout<<"Inserted Successfully"<<endl;
            }
        }
        else if(ins=="DELETE")
        {
            p=0;
            for(i=0;i<V.size();i++)
            {
                if(V[i]==str)
                {
                    V[i]="*";
                    cout<<"Deleted Successfully"<<endl;
                    p=1;
                    break;
                }
            }
            if(p==0)
                cout<<"Not Found"<<endl;
        }
        else if(ins=="COUNT")
        {
            mx=0;
            for(i=0;i<V.size();i++)
            {
                ss=V[i];
                if(ss=="*")
                    continue;
                cnt=0;
                for(j=ss.size()-1,k=str.size()-1;j>=0;j--,k--)
                {
                    if(ss[j]==str[k])
                        cnt++;
                }
                if(cnt==ss.size())
                    mx++;
            }
            cout<<mx<<endl;
        }

    }

    return 0;
}
