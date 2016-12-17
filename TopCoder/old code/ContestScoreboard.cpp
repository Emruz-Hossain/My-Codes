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
 struct bt
{
    int score,time;
};
struct st
{
    string name;
    vector<bt>v;
};
struct ct
{
    string name;
    int scr,idx;
};
vector<st>TI;
bool cmp(bt a, bt b)
{
    return a.time<b.time;
}
bool cmp2(ct a,ct b)
{
    if(a.scr==b.scr)
    {
            return a.name<b.name;
    }
    return a.scr>b.scr;
}
vector<ct>vv;
void solve(int time)
{

    ct a;
    int i,j;
    vv.clear();
    for(i=0;i<TI.size();i++)
    {
        a.name=TI[i].name;
        a.idx=i;
        a.scr=0;
        for(j=0;j<TI[i].v.size();j++)
        {
            if(TI[i].v[j].time<=time)
            {
                a.scr+=TI[i].v[j].score;
            }
            else
                break;
        }
        vv.push_back(a);
    }
    sort(vv.begin(),vv.end(),cmp2);
}
struct ContestScoreboard{

vector <int> findWinner(vector <string> scores)
{
    vector <int> ret;
    int l,i,j,r,p,num,k;
    l=scores.size();
    st a;

    for(i=0;i<l;i++)
    {
        string ss=scores[i];
       //cout<<ss<<endl;
        a.name="";
        a.v.clear();
        for(j=0;j<ss.size();j++)
        {
            if(ss[j]==' ')
            {
                j++;
                break;
            }
            a.name+=ss[j];
        }
        for(k=j;k<ss.size();k++)
        {
            num=0;
            for(r=k;r<ss.size();r++)
            {
                if(ss[r]=='/')
                {
                    r++;
                    break;
                }
                num=num*10+ss[r]-'0';
            }
            bt b;
            b.score=num;
            num=0;
            for(p=r;p<ss.size();p++)
            {
                if(ss[p]==' ')
                {
                   k=p;
                    break;
                }
                num=num*10+ss[p]-'0';
            }
            k=p;
            b.time=num;
            //cout<<b.score<<" "<<b.time<<endl;
            a.v.push_back(b);
        }
        TI.push_back(a);
    }
    for(i=0;i<TI.size();i++)
    {
        sort(TI[i].v.begin(),TI[i].v.end(),cmp);
    }
    ret.resize(l,0);
    solve(0);
    ret[vv[0].idx]=1;
    for(i=0;i<l;i++)
    {
        for(j=0;j<TI[i].v.size();j++)
        {
            solve(TI[i].v[j].time);
            ret[vv[0].idx]=1;
        }
    }
    for(i=0;i<l;i++)
        TI.clear();
    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"WHHJ 41/350 496/33 402/695 798/979 356/995 97/932 982/952 820/271 822/397 912/52 302/860", "CGRRGIB 77/688 78/808 666/317 137/883 431/78 802/560 180/890 845/508 631/493 889/581", "DOKCSG 22/642 606/898 342/649 422/313 821/48 318/148 78/737", "BTR 394/743 778/169 422/707 161/954 336/182 450/186 754/717 334/523 413/865", "TCTBIK 253/308", "UCNE 678/484 682/392 273/570 382/875 733/601", "MNDOQ 598/31 524/295 473/304", "PTHS 897/997 140/462 624/210 800/9 403/794 876/821 643/944 126/114 110/418 906/86", "NNP 425/250 189/137 198/367 912/736 138/696 109/676 809/960 527/529 65/494 764/460", "LKOCKQ 860/24 431/304 477/67 690/810 915/182 911/298", "IGO 102/58 562/564 857/132 551/855 761/330 635/904", "YBHS 598/475 120/488 44/255", "BQVY 827/411", "IQBA 139/984 387/814", "DMXHVL 478/977 309/210 114/268", "MGP 115/884 682/635 678/879 88/515 764/535 501/91 660/785 248/684 976/623 200/927", "YRKB 413/236 165/475 283/972 670/746", "KHCWX 959/485 655/403", "BWFDSD 320/204", "RTR 577/865 578/744 114/279 248/566 250/787 946/106 830/315 484/902", "HMKGCB 866/618 618/725 210/388 847/463 211/553", "KRESVBG 75/781 806/189 254/540 960/632 680/237 964/656 890/716 201/260 33/892 233/34"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findWinner(Arg0)); }
	void test_case_1() { string Arr0[] = {"GLP 1/114 1/195 1/171 1/19 1/146 1/29","BKPF 1/57 1/187 1/277 1/21 1/223 1/35"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findWinner(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA 248/2 495/5 993/7","BBB 244/6 493/7 990/10", "CCC 248/2 495/5 993/10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findWinner(Arg0)); }
	void test_case_3() { string Arr0[] = {"UBA 10/2 30/4 25/3 999/1000", "UNC 1/3 3/20 40/50", "UNLP 2/2 3/3 4/4 100/100", "UNR 999/1000000 999/999999", "UNS 999/100000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
ContestScoreboard ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
