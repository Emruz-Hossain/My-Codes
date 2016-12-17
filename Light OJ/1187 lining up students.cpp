
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
  int read(void)
 {
     int sm=0;
     while(1)
     {
        int c;
        //c= getchar_unlocked();
       c= getchar();
         if(c<'0'||c>'9')
            break;
         else
            c=c-'0';
        sm=sm*10+c;
     }
     return sm;
 }
int main()
{
   int n,p,x,i,t,id;
   t=read();
   for(x=1;x<=t;x++)
   {
       n=read();
       p=read();
       id=1;
       for(i=2;i<=n;i++)
       {
           p=read();
           if(i-p<=id)
            id++;
       }
       printf("Case %d: %d\n",x,id);
   }

    return 0;
}
