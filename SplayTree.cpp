
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
#define     eps  1e-9
#define     mod  1000000007
#define     PI   2.0*acos(0.0)
#define     imax 2147483647
#define     lmax 9223372036854775807LL

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
const int sz=100005;
struct Node
{
	Node *l;
	Node *r;
	Node *p;
	int v;
};

Node *root;

void rotateRight(Node *Y)
{
	Node *P = Y -> p;
	Node *X = Y -> l;
	Node *B = X -> r;

	if(P)	// Y has parent.
	{
		if(P -> l == Y)	//Y is left child of its parent.
			P -> l = X;
		else			// Y is right child of its parent.
			P -> r = X;
	}
	if(B)	// X has right sub-tree.
	{
		B -> p = Y;
	}

	X -> p = P;
	X -> r = Y;

	Y -> p = X;
	Y -> l = B;
}

void rotateLeft(Node *Y)
{
	Node *P = Y -> p;
	Node *X = Y -> r;
	Node *B = X -> l;

	if(P)	// Y has parent.
	{
		if(P -> l == Y)	//Y is left child of its parent.
			P -> l = X;
		else			// Y is right child of its parent.
			P -> r = X;
	}
	if(B)	// X has left sub-tree.
	{
		B -> p = Y;
	}

	X -> p = P;
	X -> l = Y;

	Y -> p = X;
	Y -> r = B;
}

void Splay(Node *X) 					//splay on node X
{
	while(true)
	{
		Node *parentOfX = X -> p;
		if(!parentOfX) 					// node X is already in the root.
			break;
		Node *grandParentOfX = parentOfX -> p;
		if(!grandParentOfX) 			// grandParentOfX is null so parentOfX is root. It is Zig.
		{
			if(parentOfX -> l == X)			// X is left child of root
				rotateRight(parentOfX);
			else						//X is right child of root
				rotateLeft(parentOfX);
		}
		else							// X has a grand parent
		{
			if(grandParentOfX ->l == parentOfX && parentOfX -> l == X )	// X is left-left child of its grand parent so it Zig-Zig
			{
				rotateRight(grandParentOfX);
				rotateRight(parentOfX);
			}
			else if(grandParentOfX ->r == parentOfX && parentOfX -> r ==X)	// X is right-right child of its grand parent so it is Zig-Zig
			{
				rotateLeft(grandParentOfX);
				rotateLeft(parentOfX);
			}
			else if(grandParentOfX -> l ==parentOfX &&parentOfX -> r ==X )	// X is left-right child of its grand parent so it is Zig-Zag.
			{
				rotateLeft(parentOfX);
				rotateRight(grandParentOfX);
			}
			else															//X is right-left child of its grand parent so  it is Zig-Zag.
			{
				rotateRight(parentOfX);
				rotateLeft(grandParentOfX);
			}
		}
	}
	root = X;
}

void Insert(int val)	//Insert val to its expected position.
{
	if(!root)	// No value inserted yet.
	{
		root = (Node *)malloc(sizeof(Node));	//allocate memory for new node.
		root -> l = NULL;
		root -> r = NULL;
		root -> p = NULL;
		root -> v = val;
		return;
	}

	Node *cur = root;
	while(true)
	{
		if((cur -> v) <= val)
		{
			if(cur -> r)
			{
				cur = cur -> r;		// go to right child.
			}
			else	// Expected position found.
			{
				(cur ->r) = (Node *)malloc(sizeof(Node));
				(cur ->r) -> l = NULL;
				(cur ->r) -> r = NULL;
				(cur ->r) -> p = cur;
				(cur ->r) -> v =val;
				cur = cur -> r;
				break;
			}
		}
		else
		{
			if(cur -> l)
			{
				cur = cur -> l;		// go to left child.
			}
			else	// Expected position found.
			{
				(cur ->l) = (Node *)malloc(sizeof(Node));
				(cur ->l) -> l = NULL;
				(cur ->l) -> r = NULL;
				(cur ->l) -> p = cur;
				(cur ->l) -> v =val;
				cur = cur -> l;
				break;
			}
		}
	}
	Splay(cur);
}

void Inorder(Node *cur)
{
	if(!cur)
		return;
	Inorder(cur -> l);
	printf(" %d", cur ->v );
	Inorder(cur -> r);
}

Node* Find(int val)
{
	if(!root)
		return NULL;
	Node *cur = root;
	while(true)
	{
		if(cur -> v == val)
			break;
		else if(cur -> v <val)
		{
			if(cur -> r)
				cur = cur -> r;
			else
				break;
		}
		else
		{
			if(cur -> l)
				cur = cur -> l;
			else
				break;
		}
	}
	Splay(cur);
	if(cur -> v == val)
		return cur;
	else
		return NULL;
}

bool Erase(int val)
{
	Node *pos = Find(val);
	if(!pos)	// value not found in tree.
		return false;
	Splay(pos);	// It is not necessay since Find methond will put th pos in root.
	Node *newRoot = pos -> l;
	if(!newRoot)	//left subtree is null.
	{
		root = pos ->r;
		root -> p =NULL;
		free(pos);
		return true;
	}
	while(newRoot -> r) 	//go to the right most node of left subtree.
	{
	    newRoot= newRoot -> r;
	}
	if(pos -> r)
	{
		newRoot -> r = pos ->r;	// connect right subtree to the right of the largest value of left subtree.
		pos -> r -> p = newRoot;
	}
	root = pos -> l;
	root -> p =NULL;
	free(pos);
	Splay(newRoot);
	return true;
}

int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
   while(true)
   {
   	scanf("%d %d",&t,&n);
   	if(t==0)
   	{
   		Insert(n);
   		pf("Successfully Inserted\n");
   		Inorder(root);
   		pf("\n");

   	}
   	else if(t==1)
   	{
   		if(Find(n))
   			printf("Value Found\n");
   		else
   			printf("Value Not Found\n");

   	}
   	else if(t==2)
   	{
   		if(Erase(n))
   		{
   			printf("Delet Successfull\n");
   			Inorder(root);
   			pf("\n");
   		}

   	}
   	else
   	{
   		pf("Invalind input\n");
   	}
   }


    return 0;
}

