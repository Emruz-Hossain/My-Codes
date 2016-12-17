//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<vector>
#define inf 1<<29
#define Sz 10
using namespace std;
struct SM
{
	int u,w;
}tmp,H[2*Sz];
vector<SM>E[Sz];
int Dis[Sz],Vis[Sz];
void Max_Heapify(int p,int n)
{
	if(p==0)
	return;
	if(H[p].w>H[n].w)
	{
		SM a=H[p];
		H[p]=H[n],H[n]=a;
		Max_Heapify(p/2,n);
	}
}
void update_Max_Heapify(int p,int n)
{
	int l,r,v=p;
	l=2*p,r=2*p+1;
	if(l<=n&&H[l].w<H[p].w)
	v=l;
	if(r<=n&&H[r].w<H[v].w)
	v=r;
	if(v!=p)
	{
		SM a=H[v];
		H[v]=H[p],H[p]=a;
		update_Max_Heapify(v,n);
	}
}
int main()
{
	int n,m,i,j,u,v,w,s,d,hs;
	while(scanf("%d%d",&n,&m)==2)
	{
		for(i=1;i<=n;i++)
		{
			E[i].clear();
			Dis[i]=inf,Vis[i]=0;
		}
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			tmp.u=v,tmp.w=w;
			E[u].push_back(tmp);
			tmp.u=u;
			E[v].push_back(tmp);
		}
		scanf("%d",&s);
		tmp.u=s,tmp.w=0;
		Dis[s]=0,H[1]=tmp,hs=1;
		while(hs)
		{
			tmp=H[1],H[1]=H[hs--];
			update_Max_Heapify(1,hs);
			u=tmp.u;
			if(!Vis[u])
			{
				Vis[u]=1;
				for(i=0,j=E[u].size();i<j;i++)
				{
					tmp=E[u][i];
					v=tmp.u,w=tmp.w;
					if(Dis[v]>Dis[u]+w)
					{
						Dis[v]=Dis[u]+w;
						tmp.u=v,tmp.w=Dis[v];
						H[++hs]=tmp;
						Max_Heapify(hs/2,hs);
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			i>1&&printf(" ");
			printf("%d",Dis[i]);
		}
		puts("");
	}
	return 0;
}
