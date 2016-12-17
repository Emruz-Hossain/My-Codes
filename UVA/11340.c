#include<stdio.h>
#include<string.h>
int main()
{
  long long int i,j,t,r,k,l,m,n,p[201],ar[201];

    char ch,st[200];
    scanf("%lld",&t);
    for(i=0;i<t;r++)
    {
        for(i=0;i<201;i++)
            p[i]=0;
        scanf("%lld",&k);
        getchar();
        for(i=0;i<k;i++)
        {
            scanf("%c",&st[i]);
            scanf("%lld",&p[i]);
            getchar();
        }
        scanf("%lld",&l);
        getchar();m=0;
        for(i=0;i<l;)
        {
            scanf("%c",&ch);

            for(j=0;j<k;j++)
                if(ch==st[j])
                  m=m+p[j];
            if(ch=='\n')
                i++;
        }

        printf("%.2lf$\n", (double)m/100);

    }
  return 0;
}
