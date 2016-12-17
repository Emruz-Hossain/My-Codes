#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXN = 222222;
int arr[MAXN];
struct Seg{
    int a,b;
}s[MAXN];
int pt[MAXN],cov[MAXN<<2],N,T,S,Q;
void build(int l,int r,int rt){
    cov[rt] = 0;
    if(l==r)return;
    int m = (l+r)>>1;
    build(lson);
    build(rson);
}
void pushDOWN(int rt){
    if(cov[rt]){
        cov[rt<<1]+=cov[rt];
        cov[rt<<1|1]+=cov[rt];
        cov[rt] = 0;
    }
}
void update(int L,int R,int l,int r,int rt){
    if(L<=l&&R>=r){
        cov[rt]++;
        return;
    }
    pushDOWN(rt);
    int m = (l+r)>>1;
    if(m>=L)update(L,R,lson);
    if(m<R)update(L,R,rson);
}
int query(int pos,int l,int r,int rt){
    if(l==r){
        return cov[rt];
    }
    pushDOWN(rt);
    int m = (l+r)>>1;
    if(pos<=m)return query(pos,lson);
    else return query(pos,rson);
}
int bs(int x){
    int l = 0,r = N-1,m;
    while(l<=r){
        m = (l+r)>>1;
        if(arr[m]==x)return m;
        else if(arr[m]>x)r = m-1;
        else l = m+1;
    }
    return -1;
}
int main(){
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        scanf("%d%d",&S,&Q);N = 0;
        for(int i=0;i<S;i++){
            scanf("%d%d",&s[i].a,&s[i].b);
            arr[N++] = s[i].a;
            arr[N++] = s[i].b;
        }
        for(int i=0;i<Q;i++){
            scanf("%d",&pt[i]);
            arr[N++] = pt[i];
        }
        sort(arr,arr+N);
        int temp = 1;
        for(int i=1;i<N;i++)if(arr[i]!=arr[i-1])arr[temp++] = arr[i];
        N = temp;
        build(0,N-1,1);
        for(int i=0;i<S;i++){
            update(bs(s[i].a),bs(s[i].b),0,N-1,1);
        }
        printf("Case %d:\n",cas);
        for(int i=0;i<Q;i++){
            printf("%d\n",query(bs(pt[i]),0,N-1,1));
        }
    }
    return 0;
}

