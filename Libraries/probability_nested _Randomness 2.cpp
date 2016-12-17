#include<stdio.h>
double probability (int N, int nestings, int target)
{
 int I, J, K;
 double A[1001], B[2001];
 // A[I] represents the probability of number I  to appear

 for (I = 0; I < N ; I++)
    A[I] = (double) 1 / N;
 for (K = 2; K <= nestings; K++)
 {
  for (I = 0; I < N; I++)
    B[I] = 0;
  // for each I between 0 and N-1 we call the function "random(I)"
  // as described in the problem statement
  for (I = N-1; I >=0; I--)
  {
   for (J = 0; J < I; J++)
        B[J] +=  (double) A[I] / I;
  }
    for (I = 0; I < N; I++)
        A[I] = B[I];
 }
  return A[target];
}
int main()
{
    printf("%lf\n",probability(4,3,1));
    return 0;
}

