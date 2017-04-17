#include<bits/stdc++.h>
#define f first
#define s second
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
using namespace std;
int fx[]={+1,-1,0,0};
int fy[]={0,0,+1,-1};
bool visit[1001][1001];
int dis[1001][1001];
int row,col;
void bfs(int s1,int s2){
   queue<pii> q;
   mem(dis,127);
   visit[s1][s2]=1;
   dis[s1][s2]=0;
   q.push(pii(s1,s2));
   while(!q.empty()){
    pii top= q.front();
    q.pop();
    for(int i=0; i<4; i++){
        int tx=top.f+fx[i];
        int ty=top.s+fy[i];
        if(tx<0 || tx>=row || ty<0 || ty>=col || visit[tx][ty]) continue;
        if(dis[tx][ty]>dis[top.f][top.s]+1)
        {
        visit[tx][ty]=1;
        dis[tx][ty]=dis[top.f][top.s]+1;
        q.push(pii(tx,ty));
        }
    }
   }
}
int main(){
  int r;
  while(scanf("%d %d",&row,&col)==2){
    if(row==0 && col==0) break;
       mem(visit,0);
    scanf("%d", &r);

    for(int i=0,r1,c1,bmb; i<r; i++){

      scanf("%d %d", &r1,&bmb);

      for(int j=0; j<bmb; j++){

        scanf("%d", &c1);

        visit[r1][c1]=1;
      }
    }
    int s1,s2,d1,d2;
    scanf("%d %d %d %d", &s1,&s2,&d1,&d2);
    bfs(s1,s2);
    printf("%d\n",dis[d1][d2]);
  }
  return 0;
}