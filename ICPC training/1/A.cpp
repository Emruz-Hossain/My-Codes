/***************************************************************
 *                   BISMILLAHIR RAHMANIR RAHIM                *
 *                      MD: EMRUZ HOSSAIN                      *
 *                         CUET-CSE-12                         *
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

//#define     inf  (double)1<<25
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

 /**************************************************Code start from here**************************/




const double EPS = 1E-9;
const double inf= 100000000000.0;
struct pt {
	double x, y;
    pt(double x=0.0, double y=0.0)
    {
        this ->x=x;
        this ->y=y;
    }
} P1,P2,P3[50005];

struct line {
	double a, b, c;

	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		//norm();
	}

//	void norm() {
//		double z = sqrt (a*a + b*b);
//		if (abs(z) > EPS)
//			a /= z,  b /= z,  c /= z;
//	}
//
//	double dist (pt p) const {
//		return a * p.x + b * p.y + c;
//	}
};

double det(double a,double b,double c,double d)  {return (double)(a*d-b*c);}

inline bool betw (double l, double r, double x) {
	return min(l,r) <= x + EPS && x <= max(l,r) + EPS;
}

//inline bool intersect_1d (double a, double b, double c, double d) {
//	if (a > b)  swap (a, b);
//	if (c > d)  swap (c, d);
//	return max (a, c) <= min (b, d) + EPS;
//}



int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,p,i,j,k,l,q,t,cnt,sm,tmp,n1,idx,cs=1;
   double x,y,x1,y1,x2,y2,r1,r;
   while(1)
   {
   scanf("%lf %lf %lf %lf %d %d",&x1,&y1,&x2,&y2,&n1,&q);
   if(!n1&&!q)
    break;
   printf("Case %d:\n",cs++);
   P1=pt(x1,y1);
   P2=pt(x2,y2);
   for(i=0;i<n1;i++)
   {
       scanf("%lf %lf",&x1,&y1);
       P3[i]=pt(x1,y1);
   }
   for(i=0;i<q;i++)
   {
       scanf("%d",&idx);
        idx--;
       line m=line(P1,P2);
       line n=line(P1,P3[idx]);
       line mm;
       mm.a=m.b,mm.b=-m.a;mm.c=-m.b*(P1.x+P2.x)/2.0+m.a*(P1.y+P2.y)/2.0;
       line nn;
       nn.a=n.b,nn.b=-n.a;nn.c=-n.b*(P1.x+P3[idx].x)/2.0+n.a*(P1.y+P3[idx].y)/2.0;

       if(fabs(det(mm.a,mm.b,nn.a,nn.b))<eps)
        printf("Impossible\n");
       else
       {
            double zn = det (mm.a, mm.b, nn.a, nn.b);

            {
                x = - 1.0*det (mm.c, mm.b, nn.c, nn.b) / zn;
                y = - 1.0*det (mm.a, mm.c, nn.a, nn.c) / zn;
            }
       // printf("-------------%lf %lf\n",x,y);
           r=sqrt((x-P3[idx].x)*(x-P3[idx].x)+(y-P3[idx].y)*(y-P3[idx].y));
           if(r>100000.0)
            printf("Impossible\n");
           else
           {
               int res=2;
               for(j=0;j<n1;j++)
               {
                   r1=sqrt((x-P3[j].x)*(x-P3[j].x)+(y-P3[j].y)*(y-P3[j].y));
                   if(r1<r+eps)
                    res++;
               }
               printf("%d\n",res);
           }
       }
   }

   }

    return 0;
}



