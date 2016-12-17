#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int ar[100],i,t,j,br[100],cr[100],p,q;
    scanf("%d",&t);
    printf("Lumberjacks:\n");
    for(j=0;j<t;j++)
    {
        p=0;q=0;
        for(i=0;i<10;i++)
        {
            scanf("%d",&ar[i]);
            br[i]=ar[i];
        }
        sort(br,br+10);
       for(i=9;i>=0;i--)
        cr[i]=br[9-i];
       for(i=0;i<10;i++)
       {
           if(ar[i]==br[i])
            p=1;
           else
            {
                p=0;
                break;
            }
       }
       for(i=0;i<10;i++)
       {
           if(ar[i]==cr[i])
            q=1;
           else
            {
                q=0;
                break;
            }
       }
       if(p==1||q==1)
        printf("Ordered\n");
       else
        printf("Unordered\n");
    }
    return 0;
}
