#include<stdio.h>
int soda_number,c,reminder,f;
void find_soda(int m)
{
    int total_bottle;
    if((m+f+reminder)>=c)
    {
    total_bottle=m+f+reminder;
    f=0;
    soda_number=soda_number+total_bottle/c;
    reminder=total_bottle-(c*(total_bottle/c));
    find_soda(total_bottle/c);
    }
}
int main()
{
    int e,N,i;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        soda_number=0;
        reminder=0;
        scanf("%d %d %d",&e,&f,&c);
        find_soda(e);
        printf("%d\n",soda_number);

    }
    return 0;

}
