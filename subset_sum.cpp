#include<stdio.h>
int main()
{
    int n,coins[10000],j;
    long long m;
    scanf(" %d %lld",&n,&m);
    long long last=(1<<n)-1; // generalizing, we have iterate from 0 to 2^n - 1
    long long i,temp,currentsum;
    i=0;
    while(i<n)
    {
        scanf(" %d",&coins[i]);
        i++;
    }
    for(i=0;i<=last;i++)
    {
        temp=i; //stored i in a different variable to save it from modification
        currentsum=0; // to keep track of the sum of values of selected coins
        j=0;
        /*-----SUBSET GENERATION PROCESS START-----*/
        printf("Checking subset : { ");
        while(j<n) // for each bit of temp
        {
            if(temp%2==1) //examining the last bit (LSB) of temp. If it is 1, we take the coin
            {
                printf("%d ",coins[j]);
                currentsum+=(coins[j]);
            }
            temp>>=1; //right shifting temp, so that we may analyze the next least significant bit in the next iteration of while loop
            j++;
        }
        /*-----SUBSET GENERATION PROCESS OVER-----*/
        printf("} Sum= %lld",currentsum);
        /*-----CONDITION EVALUATION FOR THE CURRENT SUBSET-----*/
        if(currentsum==m)
        {
            printf("Found solution subset");
            //break;
        }
        /*-----CONDITION EVALUATION OVER-----*/
        printf("\n");
    }
    return 0;
}
