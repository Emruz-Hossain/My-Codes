#include<stdio.h>
#include<string.h>
int A[10];
void Swap(int &n,int &m)
{
	if(n==m)
	return;
	n^=m;
	m^=n;
	n^=m;
}
void Max_Heapify(int p,int n)
{
	if(p==0)
	return;
	if(A[p]<n)
	{
		Swap(A[p],n);
		Max_Heapify(p/2,n);
	}
}
void update_Max_Heapify(int p,int n)
{
	int l,r,v=p;
	l=2*p,r=2*p+1;
	if(l<=n&&A[l]>A[p])
	v=l;
	if(r<=n&&A[r]>A[v])
	v=r;
	if(v!=p)
	{
		Swap(A[p],A[v]);
		update_Max_Heapify(v,n);
	}
}
int main()
{
    int i,j,k,n,m;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&A[i]);
            Max_Heapify(i/2,A[i]);
        }
        for(i=1,m=n;i<=n;i++)
        {
        	Swap(A[1],A[m]);
        	update_Max_Heapify(1,--m);
        }
        for(i=1;i<=n;i++)
        {
        	i>1&&printf(" ");
        	printf("%d",A[i]);
        }
        printf("\n");
    }
}
