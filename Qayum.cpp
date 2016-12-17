//Bismillah Hir-rah manir Rahim

#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
#define pb push_back
#define ll long long
#define eps 1e-10


struct P
{
    double x;
    double y;
    P(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
};

P MV(P aa,P bb){ return P(bb.x-aa.x,bb.y-aa.y);}//Make Vector
double DP(P aa,P bb){ return (aa.x*bb.x+aa.y*bb.y);}//Dot Product
double CP(P aa,P bb){ return (aa.x*bb.y-aa.y*bb.x);}//Cross Product
///double V(P aa){return (aa.x*aa.x+aa.y*aa.y);}//Value of Vector
double VA(P aa){return (sqrt(DP(aa,aa)));}//Value of Vector
P VL(P aa,double l){ double m=VA(aa); return P((aa.x/m)*l,(aa.y/m)*l);}// Make Vector of 'l' length
double TRIANGLE(P aa,P bb){ return (CP(aa,bb)/2.0);}//Area of Triangle


double dis(P aa,P bb){return sqrt(((aa.x-bb.x)*(aa.x-bb.x))+((aa.y-bb.y)*(aa.y-bb.y)));}


inline bool intersectOnLine(int a,int b,int c,int d)
{
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    return max(a,c)<=min(b,d);
}

P pivot;

    bool comp1(P a,P b)
    {
        if(a.y<b.y)
        {
            return true;
        }
        else if(a.y==b.y)
        {
            if(a.x<b.x)return true;
            else return false;
        }
        return false;
    }

    bool comp2(P a,P b)
    {
        double c=CP(MV(pivot,a),MV(pivot,b));
        if(c)
            return c>0.0;
        return dis(pivot,a)<dis(pivot,b);
    }
int main()
{
    int n,i;
    P s[100];
    cout<<"Enter number of input: "<<endl;

    cin>>n;
    for(i=0;i<n;i++)
    {
        sf("%lf%lf",&s[i].x,&s[i].y);
    }

    //First sort(find pivot value)

    sort(s,s+n,comp1);
    pivot=s[0];

    //2nd sort(find minimum distant value from pivot)
    sort(s+1,s+n,comp2);
    P second=s[1];

    stack<P>sta;
    sta.push(pivot);
    sta.push(second);
    double c=0.0;
    P t,tt;
    for(i=2;i<n;i++)
    {
        t=sta.top();
        sta.pop();
        tt=sta.top();
        sta.push(t);
        while(CP(MV(sta.top(),tt),MV(sta.top(),s[i]))>0.0)
        sta.pop();
        sta.push(s[i]);

    }
    //convex has been created on stack
cout<<"\nPoints are: \n";
    while(!sta.empty())
    {
        P nn=sta.top();
        cout<<nn.x<<" , "<<nn.y<<endl;
        sta.pop();
    }


}
