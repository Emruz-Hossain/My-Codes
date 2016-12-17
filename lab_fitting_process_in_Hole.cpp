#include<bits/stdc++.h>
using namespace std;
int process[100],hole[100];
int main()
{
    int mn=100000,i,j,choice;
    srand(time(NULL));
    int number_of_process=5+rand()%10;
    int number_of_hole=number_of_process+rand()%10;
    for(i=1;i<=number_of_process;i++)
    {
        process[i]=1+rand()%1000;
        mn=min(mn,process[i]);
    }
    for(i=1;i<=number_of_hole;i++)
    {
        hole[i]=mn+rand()%1000;
    }
    printf("Number of process: %d\n",number_of_process);
    for(i=1;i<=number_of_process;i++)
        printf("%d ",process[i]);
    printf("\n");
    printf("Number of Hole: %d\n",number_of_hole);
    for(i=1;i<=number_of_hole;i++)
    {
        printf("%d ",hole[i]);
    }
    printf("\n");
    printf("Enter a method of process distribution:\n");
    printf("1. Frist fit.\n2. Best fit.\n3. Worst fit.\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        for(i=1;i<=number_of_process;i++)
        {
            printf("\n");
           int flag=0;
           for(j=1;j<=number_of_hole;j++)
           {
               if(hole[j]>=process[i])
               {
                   flag=1;
                   break;
               }
           }
           if(!flag)
            printf("Process P%d can not be distributed to any hole.\n",i);
           else
           {
               printf("Process P%d with size %d has been assigned to hole h%d with size %d.\nHole status:\n",i,process[i],j,hole[j]);
               hole[j]-=process[i];
               for(j=1;j<=number_of_hole;j++)
                    printf("%d ",hole[j]);
               printf("\n");
           }

        }
    }
    else if(choice==2)
    {
        for(i=1;i<=number_of_process;i++)
        {
            printf("\n");
           int flag=0,id,mn=100000;
           for(j=1;j<=number_of_hole;j++)
           {
               if(hole[j]>=process[i]&&hole[j]<mn)
               {
                   flag=1;
                   mn=hole[j];
                   id=j;
               }
           }
           if(!flag)
            printf("Process P%d can not be distributed to any hole.\n",i);
           else
           {
               printf("Process P%d with size %d has been assigned to hole h%d with size %d.\nHole status:\n",i,process[i],id,hole[id]);
               hole[id]-=process[i];
               for(j=1;j<=number_of_hole;j++)
                    printf("%d ",hole[j]);
               printf("\n");
           }

        }
    }
    else
    {
        for(i=1;i<=number_of_process;i++)
        {
            printf("\n");
           int flag=0,id,mx=-100000;
           for(j=1;j<=number_of_hole;j++)
           {
               if(hole[j]>=process[i]&&hole[j]>mx)
               {
                   flag=1;
                   mx=hole[j];
                   id=j;
               }
           }
           if(!flag)
            printf("Process P%d can not be distributed to any hole.\n",i);
           else
           {
              printf("Process P%d with size %d has been assigned to hole h%d with size %d.\nHole status:\n",i,process[i],id,hole[id]);
                hole[id]-=process[i];
               for(j=1;j<=number_of_hole;j++)
                    printf("%d ",hole[j]);
               printf("\n");
           }

        }
    }
}
