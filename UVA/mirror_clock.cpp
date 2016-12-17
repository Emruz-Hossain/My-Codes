#include<stdio.h>
int main()
{
    int x,y,a,b,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d:%d",&a,&b);
        if(a!=12 && a!=11){
        x=11-a;
        y=60-b;
        if(x<10 && y<10){
                printf("%02d:%02d\n",x,y);
                 }
               else if(y<10 && x>10){
                printf("%d:%02d\n",x,y);
                }
                else if(y>=10 && x<10){
                    printf("%02d:%d\n",x,y);
                }

              else
                    printf("%d:%d\n",x,y);
        }
        if(a==12 && b==0){
            printf("%d:%02d\n",a,b);
        }
        if(a==12 && b!=0){
            y=60-b;
            x=11;
            if(y<10){
                printf("%d:%02d\n",x,y);
            }
            else
            printf("%d:%d\n",x,y);
        }
        if(a==11 && b!=0){
            y=60-b;
            x=12;
            if(y<10){
                printf("%d:%02d\n",x,y);
            }
            else
            printf("%d:%d\n",x,y);
        }
        if(a==11 && b==0){
                x=1;
            printf("%02d:%02d\n",x,b);
        }
    }
    return 0;
}
