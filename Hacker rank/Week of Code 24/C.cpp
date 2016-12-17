/**************************************
 *     BISMILLAHIR RAHMANIR RAHIM     *
 *        MD: EMRUZ HOSSAIN           *
 *           CUET-CSE-12              *
 **************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 typedef unsigned long long ull;

#define     mem(x,y)   memset(x,y,sizeof(x))
#define     PB(x)      push_back(x)
#define     POB()      pop_back()
#define     SZ(a)      a.size()
#define     len(a)     strlen(a)
#define     SQR(a)     (a*a)
#define     all(v)     v.begin(),v.end()
#define     fr(i,a,b)  for(i=a;i<=b;i++)
#define     rfr(i,a,b) for(i=a;i>=b;i--)
#define     sf  scanf
#define     pf  printf
#define     mkp make_pair
#define     fs  first
#define     sd  second

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0)return 1;if (p%2 == 0){ll s = BigMod(b,p/2,m)%m;return (s*s)%m;}ll sm=((b%m)*(BigMod(b,p-1,m)%m))%m;return sm;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Swap(T &a,T &b) {T tmp=a;a=b;b=tmp;}
int Set(int N,int pos){return N=N|(1<<pos);}
int Reset(int N,int pos){return N=N&~(1<<pos);}
bool Check(int N,int pos){return (bool)(N&(1<<pos));}
double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
int toInt(string s){int sm;stringstream ss(s);ss>>sm;return sm;}
template<class T>inline bool readfast(T &x)
{
    int c=getx();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getx();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getx())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int R[]={1,-1,0,0,1,-1,-1,1};   int C[]={0,0,1,-1,1,-1,1,-1}; //move in 8 direction
int KR[]={-2,-2,-1,1,2,2,-1,1}; int KC[]={1,-1,2,2,1,-1,-2,-2}; //move of knight

////code of sieve
//int pml=10000008,np=0;
//char prm[10000009];
//int prime[800000];
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i+=2){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';prm[1]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i+=2){if(prm[i]!='*')prime[np++]=i;}*/}
struct P
{
    double x,y;
    P(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
};
P mkv(P ae,P be){return P(be.x-ae.x,be.y-ae.y);}
double dtp(P ae,P be){return (ae.x*be.x+ae.y*be.y);}
double crp(P ae,P be){return (ae.x*be.y-ae.y*be.x);}
double val(P ae){return sqrt(dtp(ae,ae));}
P vresize(P ae,double llen){double v=val(ae);return P(ae.x*llen/v,ae.y*llen/v);}
double ART(P ae,P be){return crp(ae,be)/2.0;}
 P rot(P ae,double ang){return P(ae.x*cos(ang)-ae.y*sin(ang),ae.y*cos(ang)+ae.x*sin(ang));}

 /*****************************Code start from here**************************/
int BC[]={1,2,3,-1,-2,-3,1,2,3,-1,-2,-3};
int BR[]={1,2,3,-1,-2,-3,-1,-2,-3,1,2,3};
int RC[]={0,0,0,0,0,0,1,2,3,-1,-2,-3};
int RR[]={1,2,3,-1,-2,-3,0,0,0,0,0,0};
char board[5][5];
int increase(int k)
{
    if(k>8)
        return 11;
    else if(k>5)
        return 8;
    else if(k>2)
        return 5;
    else
        return 2;

}
int rec(int player,int rem)
{
    if(rem==0)
        return 0;
    int p=0,i,j,k,x,y;
    if(player==0)
    {
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(board[i][j]>='A'&&board[i][j]<='Z')
                {
                    if(board[i][j]=='Q')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+RR[k];
                            y=j+RC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='a'&&board[x][y]<='z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='Q';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[i][j]='Q';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='Q';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[x][y]=tmp;
                                    board[i][j]='Q';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+BR[k];
                            y=j+BC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='a'&&board[x][y]<='z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='Q';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[i][j]='Q';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='Q';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[x][y]=tmp;
                                    board[i][j]='Q';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }

                    }
                    else if(board[i][j]=='N')
                    {
                        for(k=0;k<8;k++)
                        {
                            x=i+KR[k];
                            y=j+KC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='a'&&board[x][y]<='z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='N';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[i][j]='N';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='N';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[x][y]=tmp;
                                    board[i][j]='N';
                                }
                            }
                        }
                    }
                    else if(board[i][j]=='R')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+RR[k];
                            y=j+RC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='a'&&board[x][y]<='z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='R';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[i][j]='R';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='R';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[x][y]=tmp;
                                    board[i][j]='R';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                    }
                    else if(board[i][j]=='B')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+BR[k];
                            y=j+BC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='a'&&board[x][y]<='z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='B';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[i][j]='B';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='B';
                                    board[i][j]='.';
                                    p|=rec(1,rem-1);
                                    board[x][y]=tmp;
                                    board[i][j]='B';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(board[i][j]>='a'&&board[i][j]<='z')
                {
                    if(board[i][j]=='q')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+RR[k];
                            y=j+RC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='A'&&board[x][y]<='Z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='q';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[i][j]='q';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='Q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='q';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[x][y]=tmp;
                                    board[i][j]='q';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+BR[k];
                            y=j+BC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='A'&&board[x][y]<='Z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='q';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[i][j]='q';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='Q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='q';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[x][y]=tmp;
                                    board[i][j]='q';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }

                    }
                    else if(board[i][j]=='n')
                    {
                        for(k=0;k<8;k++)
                        {
                            x=i+KR[k];
                            y=j+KC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='A'&&board[x][y]<='Z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='n';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[i][j]='n';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='Q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='n';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[x][y]=tmp;
                                    board[i][j]='n';
                                }
                            }
                        }
                    }
                    else if(board[i][j]=='r')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+RR[k];
                            y=j+RC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='A'&&board[x][y]<='Z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='r';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[i][j]='r';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='Q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='r';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[x][y]=tmp;
                                    board[i][j]='r';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                    }
                    else if(board[i][j]=='b')
                    {
                        for(k=0;!p&&k<12;k++)
                        {
                            x=i+BR[k];
                            y=j+BC[k];
                            if(x>=1&&x<=4&&y>=1&&y<=4&&(board[x][y]=='.'||(board[x][y]>='A'&&board[x][y]<='Z')))
                            {
                                if(board[x][y]=='.')
                                {
                                    board[x][y]='b';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[i][j]='b';
                                    board[x][y]='.';
                                }
                                else
                                {
                                    if(board[x][y]=='Q')
                                        return 0;
                                    char tmp=board[x][y];
                                    board[x][y]='b';
                                    board[i][j]='.';
                                    p|=rec(1,rem);
                                    board[x][y]=tmp;
                                    board[i][j]='b';
                                    k=increase(k);
                                }
                            }
                            else
                            {
                                k=increase(k);
                            }
                        }
                    }
                }
            }
        }
    }
    return !p;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp,w;
   sf("%d",&t);
   while(t--)
   {
       for(i=1;i<=4;i++)
       {
           for(j=1;j<=4;j++)
           {
               board[i][j]='.';
           }
       }
       sf("%d %d %d",&w,&b,&m);
       getchar();
       char ch,clm;
       for(i=0;i<w;i++)
       {
           sf("%c %c %d",&ch,&clm,&r);
           c=clm-'A'+1;
           board[r][c]=ch;
       }
       for(i=0;i<b;i++)
       {
           sf("%c %c %d",&ch,&clm,&r);
           c=clm-'A'+1;
           ch=tolower(ch);
           board[r][c]=ch;
       }
       if(!rec(0,m))
        pf("YES\n");
       else
        pf("NO\n");
   }

    return 0;
}
