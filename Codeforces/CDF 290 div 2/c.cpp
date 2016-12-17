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
int flag;
struct st
{
    int endm;
    struct bt
    {
        int ch,ptr;
    } ar[5];
}trie[300005];
char ss[700005];
int root=0;
void built(int rt,int p,int l)
{
    int ch;
    if(p==l)
        return;
    ch=ss[p]-'a';
    if(trie[rt].ar[ch].ch==1)
    {
        built(trie[rt].ar[ch].ptr,p+1,l);
    }
    else
    {
        trie[rt].ar[ch].ch=1;
        root++;
        trie[rt].ar[ch].ptr=root;
        if(p==l-1)
        trie[rt].endm=1;
        built(trie[rt].ar[ch].ptr,p+1,l);
    }
}
int src(int rt,int p,int l,int dif)
{
    int ch=ss[p]-'a';
    int p1,p2,p3;
    if(p==l-1&&dif==1)
    {
        if(trie[rt].ar[ch].ch==1&&trie[rt].endm==1)
          return 1;
        else
            return 0;
    }
    if(p+1<=l)
    {
        if(trie[rt].ar[ch].ch==1)
        {
              p1=src(trie[rt].ar[ch].ptr,p+1,l,dif);
              if(ch==0)
              {
                  p2=src(trie[rt].ar[1].ptr,p+1,l,dif+1);
                   p3=src(trie[rt].ar[2].ptr,p+1,l,dif+1);
              }
              else if(ch==1)
              {
                  p2=src(trie[rt].ar[0].ptr,p+1,l,dif+1);
                p3=src(trie[rt].ar[2].ptr,p+1,l,dif+1);
              }
              else
              {
                  p2=src(trie[rt].ar[1].ptr,p+1,l,dif+1);
                 p3=src(trie[rt].ar[0].ptr,p+1,l,dif+1);
              }
              return max(p1,max(p2,p3));
        }
        else
        {
            p1=src(trie[rt].ar[0].ptr,p+1,l,dif+1);
            p2=src(trie[rt].ar[1].ptr,p+1,l,dif+1);
            p3=src(trie[rt].ar[2].ptr,p+1,l,dif+1);
            return max(p1,max(p2,p3));

        }
    }



}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,n,p,x,i,j,q,r,l;
    scanf("%d %d",&n,&m);
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
        flag=0;
        r=src(0,0,l,0);
        if(r)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
