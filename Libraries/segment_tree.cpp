//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#define Sz 100005
int tree[4*Sz],A[Sz],Id[Sz];
int Max(int a,int b)
{
	return a>b?a:b;
}
void build_tree(int p,int l,int r)
{
	if(l==r)
	{
		tree[p]=A[l];
		Id[l]=p;
		return;
	}
	int m=(l+r)/2;
	build_tree(2*p,l,m);
	build_tree(2*p+1,m+1,r);
	tree[p]=Max(tree[2*p],tree[2*p+1]);
}
void update(int p,int l,int r,int x,int y)
{
	if(l>y||r<x||l>=x&&r<=y)
	return;
	int m=(l+r)/2;
	update(2*p,l,m,x,y);
	update(2*p+1,m+1,r,x,y);
	tree[p]=Max(tree[2*p],tree[2*p+1]);
}
int query(int p,int l,int r,int x,int y)
{
	if(l>y||r<x)
	return 0;
	if(l>=x&&r<=y)
	return tree[p];
	int m=(l+r)/2;
	return Max(query(2*p,l,m,x,y),query(2*p+1,m+1,r,x,y));
}
int main()
{
	int n,q,l,r,ind,v,a,i;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
		build_tree(1,1,n);
		printf("Enter query:\n");
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&a);
			if(a==1)
			{   scanf("%d%d",&ind,&v);
				tree[Id[ind]]=v;
				update(1,1,n,ind,ind);
			}
			else
			{
				scanf("%d%d",&l,&r);
				printf("%d\n",query(1,1,n,l,r));
			}
			for(i=1;i<=n;i++)
                printf("%d ",tree[i]);
            printf("\n");
		}
	}
	return 0;
}
