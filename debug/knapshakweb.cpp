#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};

int knapsack(int nItems, int size, int weights[], int values[])
{
    int i,j;

    for (i=1;i<=nItems;i++)
        {
        for (j=0;j<=size;j++)
        {
            if (weights[i-1]<=j)
            {
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
            }
            else
            {
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

int main(){
    int nItems;
    int knapsackSize;
    int weights[100];
    int values[100] ;
    int i,j;
    scanf("%d",&nItems);
    for(i=0;i<nItems;i++)
        scanf("%d %d",&weights[i],&values[i]);
    scanf("%d",&knapsackSize);
    printf("Max value = %d",knapsack(nItems,knapsackSize,weights,values));

    return 0;
}
