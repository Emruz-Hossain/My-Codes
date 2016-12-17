#include<stdio.h>
int height_lady[50050],height_luchu[30000],smalest,talest,k,l;
void finder(int m,int high_index)
{
    int mid_indx,low_indx=0;
    while(low_indx<=high_index)
    {
        mid_indx=(high_index+low_indx)/2;
        if(height_lady[mid_indx]==m)
            break;
        if(height_lady[mid_indx]>m)
            high_index=mid_indx-1;
        else
            low_indx=mid_indx+1;
    }
    if(height_lady[mid_indx]==m)
    {
        k=mid_indx;
        l=mid_indx;
        while(m==height_lady[k])
        {
            smalest=height_lady[k-1];
            k--;
        }

       while(m==height_lady[l])
{
            talest=height_lady[l+1];
            l++;
        }
        printf("%d %d\n",smalest,talest);
    }
}
int main()
{
    int no_lady,no_quary,i;
    while(scanf("%d",&no_lady)==1)
    {
        for(i=0;i<no_lady;i++)
            scanf("%d",&height_lady[i]);
        scanf("%d",&no_quary);
        for(i=0;i<no_quary;i++)
            scanf("%d",&height_luchu[i]);
        for(i=0;i<no_quary;i++)
            finder(height_luchu[i],no_lady-1);
    }
    return 0;
}
