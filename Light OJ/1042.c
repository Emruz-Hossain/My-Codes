#include<stdio.h>
#include<math.h>
#include<string.h>
char a[100];
int k;
void bin(int n)
{
    int d;
    if(n==0)
        return;
    d=n%2;
    bin(n/2);
    a[k]=d+'0';
    k++;
}
long long dec(void)
{
    long long p=0,n=0,l,i;
    l=strlen(a);
    for(i=l-1;i>=0;i--)
    {
        n=n+((a[i]-'0')*pow(2,p));
        p++;
    }
    return n;
}
int main()
{
    long long t,i,n,l,j,temp,r,x,y,z;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        memset(a,0,sizeof(a));
        k=0;
        scanf("%lld",&n);
        bin(n);
        a[k]='\0';
        l=strlen(a);
        for(j=l-1;j>=0;j--)
        {
            if(a[j]=='1'&&a[j-1]=='0')
                {
                    a[j]='0';
                    a[j-1]='1';
                    for(x=j+1;x<l;x++)
                    {
                        temp=a[x];
                        for(y=x;y<l;y++)
                        {
                            if(a[x]>a[y])
                            {
                                a[x]=a[y];
                                a[y]=temp;
                            }

                        }
                    }
                    break;
                }

        }

        if(j<0)
        {
            temp=a[1];
            a[0]='1';
            a[1]='0';
            for(j=2;j<=l;j++)
            {
                z=a[j];
               a[j]=temp;
               temp=z;

            }
            a[j]='\0';
            l=strlen(a);
            for(x=2;x<l;x++)
                    {
                        temp=a[x];
                        for(y=x;y<l;y++)
                        {
                            if(a[x]>a[y])
                            {
                                a[x]=a[y];
                                a[y]=temp;
                            }

                        }
                    }

        }
            r=dec();
            printf("Case %lld: %lld\n",i,r);

    }
    return 0;
}
