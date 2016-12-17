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
struct st
{
    int endm;
    struct bt
    {
        int ch,ptr,freq;
    } ar[50];
}trie[100];
char ss[100];
int root=0;
void built(int rt,int p,int l)
{
    int ch;
    if(p==l)
        return;
    ch=ss[p]-'a';
    if(trie[rt].ar[ch].ch==1)
    {
        trie[rt].ar[ch].freq++;
        built(trie[rt].ar[ch].ptr,p+1,l);
    }
    else
    {
        trie[rt].ar[ch].ch=1;
        trie[rt].ar[ch].freq=1;
        root++;
        trie[rt].ar[ch].ptr=root;
        if(p==l-1)
        trie[rt].endm=1;
        built(trie[rt].ar[ch].ptr,p+1,l);
    }
}
int src(int rt,int p,int l)
{
    int ch=ss[p]-'a';
    if(p==l-1&&trie[rt].ar[ch].ch==1)
        return trie[rt].ar[ch].freq;
    else if(p+1<=l&&trie[rt].ar[ch].ch==1)
    {
           return  src(trie[rt].ar[ch].ptr,p+1,l);
    }
    else
        return 0;

}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",&ss);
        l=strlen(ss);
        built(0,0,l);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",&ss);
        l=strlen(ss);
        r=src(0,0,l);
        printf("%d\n",r);
    }

    return 0;
}

//10
//apple
//applo
//ass
//assasian
//bad
//badminton
//trie
//tread
//special
//opera
//15
//ass
