#include <stdio.h>
#include <math.h>

#define SIZE_N 1000
#define SIZE_P 1000

bool flag[SIZE_N+5];
int primes[SIZE_P+5];

int seive()
{
	int i,j,total=0,val;

	for(i=2;i<=SIZE_N;i++) flag[i]=1;

    	val=sqrt(SIZE_N)+1;

	for(i=2;i<val;i++)
        	if(flag[i])
            		for(j=i;j*i<=SIZE_N;j++)
                		flag[i*j]=0;

   	for(i=2;i<=SIZE_N;i++)
       	if(flag[i])
            		primes[total++]=i;

	return total;
}

int divisor(int N)
{
    	int i,val,count,sum;

    	val=sqrt(N)+1;
    	sum=1;
    	for(i=0;primes[i]<val;i++)
    	{
       	if(N%primes[i]==0)
        	{
            		count=0;
            		while(N%primes[i]==0)
            		{
                		N/=primes[i];
                		count++;
            		}
            		sum*=(count+1);
        	}
    	}
    	if(N>1)
       	sum=sum*2;
    	return sum;
}

int main()
{
    	int total=seive();
    	int n;

    	while(scanf("%d",&n)==1)
    	{
       	printf("%d No Of divisor:%d\n",n,divisor(n));
    	}
    	return 0;
}

// 	5 No Of divisor:2
// 	8 No Of divisor:4
// 	100 No Of divisor:9
//	568 No Of divisor:8
//	48 No Of divisor:10
