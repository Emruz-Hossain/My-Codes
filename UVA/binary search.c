#include<stdio.h>
int main()
{
    int aray[100],i,low_indx,high_indx,mid_indx,q;
    for(i=0;i<20;i++)
        scanf("%d",&aray[i]);
    low_indx=0;
    high_indx=19;
    scanf("%d",&q);
    while(low_indx<=high_indx)
    {
        mid_indx=(high_indx+low_indx)/2;
        if(aray[mid_indx]==q)
            break;
        if(q<aray[mid_indx])
            high_indx=mid_indx-1;
        if(q>aray[mid_indx])
            low_indx=mid_indx+1;

    }
    if(low_indx>high_indx)
        printf("Not found");
    else
    printf("%d",mid_indx);
    return 0;

}
