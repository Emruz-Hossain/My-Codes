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
#include<bits/stdc++.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2600005
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};

struct st
{
    int numOfChild;
    struct bt
    {
        int ch,ptr,worstCaseQueryNo;
    } ar[30];
}trie[sz];

struct st2
{
    int cnt,ch;
};
char ss[sz];
vector<st2>V;
int root=0,k;
bool cmp(st2 a, st2 b)
{
    return a.cnt>b.cnt;
}
int built(int rt,int p,int l)
{
    int ch,q,i;
    if(p==l)
        return 0;
    ch=ss[p]-'a';
    if(trie[rt].ar[ch].ch==1)
    {
        q= built(trie[rt].ar[ch].ptr,p+1,l);
        trie[rt].ar[ch].worstCaseQueryNo=q+1;
    }
    else
    {
        trie[rt].ar[ch].ch=1;
        root++;
        trie[rt].ar[ch].ptr=root;
        q= built(trie[rt].ar[ch].ptr,p+1,l);
        trie[rt].ar[ch].worstCaseQueryNo=q+1;
    }
        V.clear();
        for(int i=0;i<26;i++)
        {
            if(trie[rt].ar[i].ch==1)
            {
                st2 aa;
                aa.ch=i;
                aa.cnt=trie[rt].ar[i].worstCaseQueryNo;
                V.push_back(aa);
            }
        }
        sort(V.begin(),V.end(),cmp);
        q=0;
        for(i=0;i<V.size();i++)
            q=max(q,V[i].cnt+i);
        return q;
}
void src(int rt,int p,int l)
{
        int ch,a;
        if(p==l)
            return;
        V.clear();
        for(int i=0;i<26;i++)
        {
            if(trie[rt].ar[i].ch==1)
            {
                st2 aa;
                aa.ch=i;
                aa.cnt=trie[rt].ar[i].worstCaseQueryNo;
                V.push_back(aa);
            }
        }
        sort(V.begin(),V.end(),cmp);
        for(int i=0;i<V.size();i++)
        {

            cout<<(char)(V[i].ch+'a')<<endl;
            cout.flush();
            cin>>a;
            if(a==1)
            {
                ch=V[i].ch;
                break;
            }
        }
        src(trie[rt].ar[ch].ptr,p+1,l);
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>ss;
        l=strlen(ss);
        built(0,0,l);
    }
    src(0,0,k);
    return 0;
}
