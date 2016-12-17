#include <bits/stdc++.h>
#define mx 200005

using namespace std;

int arr[100005],n,ind;

int tree[mx*3],sum[mx*3];

void build_tree(int node,int b,int e)
{

    if(b==e)
    {
        if(b<=n)
        {
            tree[node] = arr[b];
            sum[node] = 1;
        }
        else
            sum[node] = 0;

        return;
    }

    int mid = (b+e)/2;

    build_tree(node*2,b,mid);

    build_tree(node*2+1,mid+1,e);

    sum[node] = sum[node*2]+sum[node*2+1];

}

void update_tree(int node,int b,int e,int ind,int val)
{
    if(ind>e||ind<b)
        return;

    if(b==e&&b==ind)
    {
        tree[node] = val;
        sum[node] = 1;
        return;
    }

    int mid = (b+e)/2;

    update_tree(node*2,b,mid,ind,val);

    update_tree(node*2+1,mid+1,e,ind,val);

    sum[node] = sum[node*2]+sum[node*2+1];

}

void query(int node,int b,int e ,int tot)
{
    if(b==e)
    {
        sum[node]=0;
        ind=tree[node];
        return;
    }

    int left = node*2;

    int right = node*2+1;

    int mid = (b+e)/2;

    if(sum[left]>=tot)
        query(left,b,mid,tot);

    else
        query(right,mid+1,e,tot-sum[left]);

    sum[node] = sum[left]+sum[right];
}

void print()
{
    for(int i=1; i<=25; i++)
        cout<<i<<" "<<sum[i]<<" "<<tree[i]<<endl;
}

int main()
{
    int test,q,i,j,tot;

    scanf("%d",&test);

    char ch[10];

    for(int a = 1; a<=test; a++)
    {
        j=1;
        scanf("%d %d",&n,&q);

        for(int x=1; x<=n; x++)
            scanf("%d",&arr[x]);

        memset(sum,0,sizeof sum);

        build_tree(1,1,n+q);
        //print();

        printf("Case %d:\n",a);

        tot=n;

        for(int b=1; b<=q; b++)
        {

            scanf(" %s %d",&ch,&i);

            if(ch[0]=='c')
            {
                if(i>tot)
                    printf("none\n");

                else
                {
                    query(1,1,n+q,i);
                    printf("%d\n",ind);
                    tot--;
                    // print();
                }
            }

            else
            {
                update_tree(1,1,n+q,n+j,i);
                j++;
                tot++;
                //print();
            }

        }

    }

    return 0;
}
