/**************************************************************
 *                          BISMILLAHIR RAHMANIR RAHIM                                *
 *                                  MD: EMRUZ HOSSAIN                                              *
 *                                           CUET-CSE-12                                                      *
 ***************************************************************/
 #include<bits/stdc++.h>
 using namespace std;
 typedef long long ll;

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
#define     read(n)       scanf("%d",&n)
#define     read2(m,n)    scanf("%d %d",&m,&n)
#define     read3(m,n,p)  scanf("%d %d %d",&m,&n,&p)
#define     readl(n)      scanf("%I64d",&n);
#define     readl2(m,n)   scanf("%I64d %I64d",&m,&n)
#define     readl3(m,n,p) scanf("%I64d %I64d %I64d",&m,&n,&p)

#define     getx() getchar()
//#define     getx() getchar_unlocked()

#define     inf  1<<25
#define     sz   20002
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)

template <typename T> T gcd(T a,T b){return (b != 0 ? gcd(b, a%b) : a);}
template <typename T> T lcm(T a, T b) { return (a/gcd(a,b)*b);}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
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
//void sieve(void){int i,j;for(i=4;i<pml;i+=2) prm[i]='*';for(i=3;i*i<=pml;i++){  for(j=2;i*j<=pml;j++)prm[i*j]='*';}
//prm[0]='*';/*prime[0]=2;np=1;for(i=3;i<pml;i++){if(prm[i]!='*')prime[np++]=i;}*/}
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

 /******************************************Code start from here**************************/
struct FourStrings{
    vector<string>v;
    vector<string>test_string;
    int visit[10],ans;
    int isFound(string ss,string ss2)
    {
        if (ss.find(ss2) != string::npos)
            return 1;
        else
            return 0;
    }
    void check(void)
    {
        string ss=test_string[0];
        string ss2,ss3,ss4,ss5;
        for(int i=1;i<test_string.size();i++)
        {
            ss2=test_string[i];
            int cnt=min(ss.size(),ss2.size());
            int flag=0;
            for(int j=cnt;j>=1;j--)
            {
               ss3=ss2.substr(0,j);
               int pos=ss.size()-j;
               int pos2=ss.size();
               ss4=ss.substr(pos,pos2);
               if(ss4==ss3)
                {
                    flag=1;
                    ss5=ss.substr(0,pos)+ss2;
                    //cout<<ss5<<endl;
                    break;
                }

            }
            if(flag)
            {
                ss=ss5;
                break;
            }
            else
                ss=ss+ss2;
        }
       // cout<<ss<<endl;
        int flag1=isFound(ss,v[0]);
         int   flag2=isFound(ss,v[1]);
            int flag3=isFound(ss,v[2]);
            int flag4=isFound(ss,v[3]);
        if(flag1&&flag2&&flag3&&flag4)
        {
          //  cout<<ss<<endl;
            ans=min(ans,(int)ss.size());
        }
    }
    void combination(int n)
    {
        if(test_string.size()==n)
        {
            check();
            return;
        }
        for(int i=0;i<4;i++)
        {
            if(visit[i]==0)
            {
                visit[i]=1;
                test_string.push_back(v[i]);
                combination(n);
                visit[i]=0;
                test_string.pop_back();
            }
        }
    }
int shortestLength(string a, string b, string c, string d)
{
    v.clear();
    test_string.clear();
    ans=1000000;
    int ret=0;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    for(int i=1;i<=4;i++)
    {
        mem(visit,0);
        combination(i);
    }
    return ret=ans;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aaabab"; string Arg1 = "ba"; string Arg2 = "bbabab"; string Arg3 ="bbbbab"; int Arg4 = 13; verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "bc"; string Arg2 = "def"; string Arg3 = "ghij"; int Arg4 = 10; verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "top"; string Arg1 = "coder"; string Arg2 = "opco"; string Arg3 = "pcode"; int Arg4 = 8; verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "thereare"; string Arg1 = "arelots"; string Arg2 = "lotsof"; string Arg3 = "ofcases"; int Arg4 = 19; verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arg0 = "aba"; string Arg1 = "b"; string Arg2 = "b"; string Arg3 = "b"; int Arg4 = 3; verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "x"; string Arg3 = "x"; int Arg4 = 1; verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
FourStrings ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
