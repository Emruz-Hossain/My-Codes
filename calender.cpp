#include<stdio.h>
int main()
{
    int l,n=0,w,i,j,k,y,f,m,y1=2006,t;
    char ch;
    scanf("%d",&y);
    if((y%400)==0||(y%4)==0 && (y%100)!=0)
        f=29;
    else
        f=28;
     if(y1>=y)
     {
         for(i=y;i<y1;i++)
          {
            if((i%400)==0||(i%4)==0 && (i%100)!=0)
            n++;
          }
         n=n+(y1-y);
     }
     else
     {
         for(i=y1;i<y;i++)
       {
        if((i%400)==0||(i%4)==0 && (i%100)!=0)
        n++;
       }
        n=n+(y-y1);
     }
    while(n>=7)
       n=n-7;
       if(y<y1)
        n=7-n;
    for(i=1;i<=12;i++)
    {
        printf("\n\n");
        if(i==1)
        {
            printf("january\n");
            m=31;
        }
        if(i==2)
        {
            printf("february\n");
            m=f;
        }
        if(i==3)
        {
            printf("march\n");
            m=31;
        }
        if(i==4)
        {
            printf("april\n");
            m=30;
        }
        if(i==5)
        {
            printf("may\n");
            m=31;
        }
        if(i==6)
        {
            printf("june\n");
            m=30;
        }
        if(i==7)
        {
            printf("july\n");
            m=31;
        }
        if(i==8)
        {
            printf("august\n");
            m=31;
        }
        if(i==9)
        {
            printf("september\n");
            m=30;
        }
        if(i==10)
        {
            printf("october\n");
            m=31;
        }
        if(i==11)
        {
            printf("november\n");
            m=30;
        }
        if(i==12)
        {
            printf("dcember\n");
            m=31;
        }
        printf("\nsun\tmon\ttues\twed\tthrus\tfri\tsat\n");
        for(k=1;k<=n;k++)
            printf("   \t");
        for(j=1;j<=m;j++)
        {
            printf("%3d\t",j);
            n++;
            if(n==7)
            {
                if(j==m);
                else
                printf("\n\n");
                n=0;
            }

        }
    }
}
