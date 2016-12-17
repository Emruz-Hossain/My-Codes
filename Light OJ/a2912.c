#include<stdio.h>
int main()
{
    int f,s,fw,sw,d,avg;
    scanf("%d %d",&f,&s);
    avg=(f+s)/2;
    if(s>f)
    {
        if((avg-f)!=(s-avg))
            d=0;
        else
            d=1;
        if(d==0)
            fw=(f-0)+(avg-f);
        else
            fw=(f-1)+(avg-f);
        sw=(6-s)+(s-avg);
    }
    else if(f>s)
    {

        if((f-avg)!=(avg-s))
            d=0;
        else
            d=1;
        fw=(6-f)+(f-avg);
        if(d==0)
        sw=(s-0)+(avg-s);
        else
            sw=(s-1)+(avg-s);
    }
    else if(f==s)
    {
        d=6;
        fw=0;
        sw=0;
    }
    printf("%d %d %d",fw,d,sw);
    return 0;

}
