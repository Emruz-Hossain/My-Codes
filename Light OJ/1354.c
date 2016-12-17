#include<stdio.h>
#include<string.h>
#include<math.h>
char ipb[500];
int b[10];
void bin(void)
{
    int c=0,l,k=0,p=0,i,j,w;
    l=strlen(ipb);
    for(i=0;i<=l;i++)
    {
        c++;
        if(ipb[i]=='.'||ipb[i]=='\0')
        {
            w=0;
            b[p]=0;
            for(j=c-2;j>=k;j--)
            {
                b[p]=b[p]+((ipb[j]-'0')*pow(2,w));
                w++;
            }
            p++;
            k=c;
        }

    }
}
int main()
{
    char ipd[500];
    int i,t,j,l,a[10],p,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        memset(ipd,0,sizeof(ipd));
        memset(ipb,0,sizeof(ipb));
         scanf("%s %s",&ipd,&ipb);
         l=strlen(ipd);
         p=0;
         a[0]=0;
         for(j=0;j<=l;j++)
         {
             if(ipd[j]!='.'&&ipd[j]!='\0')
             a[p]=a[p]*10+(ipd[j]-'0');
             else
             {
                  p++;
                  a[p]=0;
             }

         }
         bin();
        if(a[0]==b[0])
        {
            if(a[1]==b[1])
            {
                if(a[2]==b[2])
                {
                    if(a[3]==b[3])
                    {
                        printf("Case %d: Yes\n",i);
                    }
                    else
                        printf("Case %d: No\n",i);
                }
                else
                    printf("Case %d: No\n",i);
            }
            else
                printf("Case %d: No\n",i);
        }
         else
            printf("Case %d: No\n",i);
    }
    return 0;

}
