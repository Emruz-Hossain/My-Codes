#include<bits/stdc++.h>
using namespace std;
struct st
{
    int idx,arival_time,processing_time,waiting_time,fininshed_time,starting_time;
}ar[100];
bool cmp(st a,st b)
{
    if(a.arival_time==b.arival_time)
        return a.idx<b.idx;
    return a.arival_time<b.arival_time;
}
bool cmp2(st a,st b)
{
    return a.idx<b.idx;
}
int main()
{
    //    freopen("output.txt","w",stdout);
    //    freopen("xinput.txt","r",stdin);
   //ios_base::sync_with_stdio(false);
   int a,b,c,d,h,m,n,p,x,y,i,j,k,l,q,r,t,cnt,sm,tmp;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
     scanf("%d %d",&ar[i].arival_time,&ar[i].processing_time);
     ar[i].idx=i;
 }
 sort(ar,ar+n,cmp);
 int next_task_time=0;
 for(i=0;i<n;i++)
 {
     if(ar[i].arival_time>=next_task_time)
     {
         ar[i].waiting_time=0;
         ar[i].starting_time=ar[i].arival_time;
         ar[i].fininshed_time=ar[i].arival_time+ar[i].processing_time;
         next_task_time=ar[i].fininshed_time;
     }
     else
     {
         ar[i].starting_time=next_task_time;
         ar[i].waiting_time=next_task_time-ar[i].arival_time;
         ar[i].fininshed_time=next_task_time+ar[i].processing_time;
         next_task_time=ar[i].fininshed_time;
     }
 }
     int total_waiting_time=0,total_processing_time=0;
     for(i=0;i<n;i++)
     {
         total_processing_time+=ar[i].processing_time;
         total_waiting_time+=ar[i].waiting_time;
     }
     double avarage_processing_time=(double)total_processing_time/(double)n;
     double avarage_waiting_time=(double)total_waiting_time/(double)n;
     printf("Avarage Processing Time: %.2lf\n",avarage_processing_time);
     printf("Avarage Waiting Time: %.2lf\n",avarage_waiting_time);
     printf("\nProcessing Order:\n");
     for(i=0;i<n;i++)
        printf("%d ",ar[i].idx+1);
     printf("\n\n");
     sort(ar,ar+n,cmp2);
     for(i=0;i<n;i++)
     {
         printf("Task %d: starting time= %d   finished time= %d\n",ar[i].idx+1,ar[i].starting_time,ar[i].fininshed_time);
     }
    return 0;
}
//5
//2 5
//3 4
//1 3
//2 6
//4 3
