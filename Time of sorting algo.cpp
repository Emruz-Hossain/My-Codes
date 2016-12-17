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
#include<ctime>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int element[1000009],ar[1000009],br[1000009],Heap[1000009],n;
vector<int>v[15];
void Swap(int x,int y){int tmp=ar[x];ar[x]=ar[y];ar[y]=tmp;}
int LOC(int l,int h)
{
    int ll,hh;
    while(l<h)
    {
        hh=h;ll=l;
        while(ar[l]<=ar[hh])
        {
            if(l==hh)
                break;
            hh--;
        }
        if(ar[l]>ar[hh])
            {
                Swap(l,hh);
                ll=l+1;l=hh;
            }
        while(ar[l]>=ar[ll])
        {
            if(l==ll)
                break;
            ll++;

        }
        if(ar[l]<ar[ll])
            {
                Swap(l,ll);
                l=ll;
            }
            h=hh-1;
    }
    return ll;
}
void Quick(int x,int y)
{
    int p;
    if(x<y)
    {
        p=LOC(x,y);
        Quick(x,p-1);
        Quick(p+1,y);
    }
}
void combine(int l,int m,int h)
{
    int i,j,k;
    j=l;k=m+1;
    for(i=l;j<=m&&k<=h;i++)
    {
        if(ar[j]<=ar[k])
        {
            br[i]=ar[j];j++;
        }
        else
        {
            br[i]=ar[k];k++;
        }
    }
    if(j>m)
    {
        for(j=k;j<=h;j++)
        {
            br[i]=ar[j];
            i++;
        }
    }
    else
    {
        for(k=j;k<=m;k++)
        {
            br[i]=ar[k];
            i++;
        }
    }
    for(i=l;i<=h;i++)
        ar[i]=br[i];
    return;
}
void Merge(int l,int h)
{
    if(l<h)
    {
    int m=(l+h)/2;
        Merge(l,m);
        Merge(m+1,h);
        combine(l,m,h);
    }

}
void Radix(int m,int mx,int p)
{
    int d,i,j,k;
    if(m>mx*10)
        return;
    for(i=0;i<=10;i++)
        v[i].clear();
    for(i=0;i<n;i++)
    {
        d=ar[i]%m;
        for(j=1;j<p;j++)
            d/=10;
        v[d].push_back(ar[i]);
    }
    k=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            ar[k++]=v[i][j];
        }
    }
    Radix(m*10,mx,p+1);
    return;
}
double bubble(void)
{
    int i,j;
    double cl;
    for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
    for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[i]>ar[j])
                Swap(i,j);
            }
        }
         cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        return cl;
}
double insertion(void)
{
    int i,j;
    double cl;
    ar[0]=-inf;
        for(i=1;i<=n;i++)
            ar[i]=element[i-1];
        cl=(double)clock();
       for(i=1;i<=n;i++)
        {
            j=i;
            while(ar[j]<ar[j-1])
            {
                Swap(j,j-1);
                j--;
            }
        }
         cl=(double)clock()-cl;
        cl=(double)cl/CLOCKS_PER_SEC;
        return cl;
}
double selection(void)
{
    int i,j,minn=0,ind;
    double cl;
    for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
    for(i=0;i<n-1;i++)
        {
            minn=ar[i];
            ind=j;
            for(j=i+1;j<n;j++)
            {
                if(ar[j]<minn)
                {
                    minn=ar[j];
                    ind=j;
                }
            }
            Swap(ind,i);
        }
         cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        return cl;
}
void Insert_heap(int ptr,int p)
{
    if(Heap[ptr/2]<=p||ptr==0)
    {
        Heap[ptr]=p;
        return;
    }
    else
    {
         Heap[ptr]=Heap[ptr/2];
         Insert_heap(ptr/2,p);
    }
}
void update_heap(int sz,int ptr)
{
    if(2*ptr>=sz)
        return;
    if(Heap[ptr]>Heap[ptr*2]||Heap[ptr]>Heap[ptr*2+1])
    {
        if(Heap[ptr*2]<Heap[ptr*2+1])
        {
            int tmp=Heap[ptr*2];
            Heap[ptr*2]=Heap[ptr];
            Heap[ptr]=tmp;
            update_heap(sz,ptr*2);
        }
        else
        {
            int tmp=Heap[ptr*2+1];
            Heap[ptr*2+1]=Heap[ptr];
            Heap[ptr]=tmp;
            update_heap(sz,ptr*2+1);
        }
    }
}
void TIE(void)
{
        //freopen("output.txt","w",stdout);
       // freopen("output.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,m,p,x,i,j,q,r,l,opt,tmp,minn,ind,maxx,sz,k;
    double cl,dr;
    system("cls");
    printf("Chose your Sorting Algorithm.\n1.Bubble sort.\n2.Insertion sort.\n3.Selection sort.\n4.Quick sort.\n5.Merge sort.\n6.Heap sort.\n7.Radix sort.\n8.All.\n9.View Sorted Array.\n10.Exit.\n");
    scanf("%d",&opt);
    if(opt==1)
        printf("Time taken by Bubble sort is %lf    sec\n",bubble());
    else if(opt==2)
        printf("Time taken by Insertion sort is %lf    sec\n",insertion());
    else if(opt==3)
        printf("Time taken by Selection sort is %lf   sec\n",selection());
    else if(opt==4)
    {
        for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
        Quick(0,n-1);
         cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Quick sort is %lf sec\n",cl);
    }
    else if(opt==5)
    {
        for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
        Merge(0,n-1);
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Merge sort is %lf sec\n",cl);

    }
    else if(opt==6)
    {
        cl=(double)clock();
        Heap[0]=-inf;
        sz=1;
        for(i=0;i<n;i++)
        {
            if(sz==1)
                Heap[1]=element[i];
            else
            Insert_heap(sz,element[i]);
            sz++;
        }
        sz--;
        k=0;
        while(sz)
        {
            ar[k++]=Heap[1];
            Heap[1]=Heap[sz];
            update_heap(sz,1);
            sz--;
        }
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Heap sort is %lf  sec\n",cl);
    }
    else if(opt==7)
    {
        maxx=0;
        for(i=0;i<n;i++)
        {
             ar[i]=element[i];
             maxx=max(maxx,ar[i]);
        }
        cl=(double)clock();
        Radix(10,maxx,1);
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Radix sort is %lf sec\n",cl);
    }
    else if(opt==8)
    {
         printf("Time taken by Bubble     sort is %lf  sec\n",bubble());
         printf("Time taken by Insertion  sort is %lf  sec\n",insertion());
         printf("Time taken by Selection  sort is %lf  sec\n",selection());
         for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
        Quick(0,n-1);
         cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Quick      sort is %lf  sec\n",cl);
        for(i=0;i<n;i++)
            ar[i]=element[i];
        cl=(double)clock();
        Merge(0,n-1);
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Merge      sort is %lf  sec\n",cl);
        cl=(double)clock();
        Heap[0]=-inf;
        sz=1;
        for(i=0;i<n;i++)
        {
            if(sz==1)
                Heap[1]=element[i];
            else
            Insert_heap(sz,element[i]);
            sz++;
        }
        sz--;
        k=0;
        while(sz)
        {
            ar[k++]=Heap[1];
            Heap[1]=Heap[sz];
            update_heap(sz,1);
            sz--;
        }
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Heap       sort is %lf  sec\n",cl);
        maxx=0;
        for(i=0;i<n;i++)
        {
             ar[i]=element[i];
             maxx=max(maxx,ar[i]);
        }
        cl=(double)clock();
        Radix(10,maxx,1);
        cl=(double)clock()-cl;
        cl=cl/CLOCKS_PER_SEC;
        printf("Time taken by Radix      sort is %lf  sec\n",cl);
    }
    else if(opt==9)
    {
        if(ar[0]>-inf)
        {
            for(i=0;i<n;i++)
            {
                printf("%d ",ar[i]);
            }
        }
        else
        {
            for(i=1;i<=n;i++)
                printf("%d ",ar[i]);
        }
    }
    else
        return;
    printf("\n");
    system("pause");
    TIE();
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int i;
    srand(time(NULL));
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        element[i]=rand()%10000;
    }
    TIE();
    return 0;
}
