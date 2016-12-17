#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2,v3,shared;
int visit1[100],visit2[100],visit3[100];
int main()
{
    int i,PM,PS,P1S,P2S,P3S,P1F,P2F,P3F,RF,TF;
    printf("Enter Size of Physical Memory(MB): ");
    scanf("%d",&PM);
    printf("Enter Page Size(MB): ");
    scanf("%d",&PS);
    printf("Enter size of P1: ");
    scanf("%d",&P1S);
    printf("Enter size of P2: ");
    scanf("%d",&P2S);
    printf("Enter size of P3: ");
    scanf("%d",&P3S);
    if(P1S>PM||P2S>PM||P2S>PM)
    {
        printf("Error. Process size is greater than total physical memory.\n");
        return 0;
    }
    RF=(PM/PS)+(PM%PS>0);
    P1F=P1S/PS+(P1S%PS>0);
    P2F=P2S/PS+(P2S%PS>0);
    P3F=P3S/PS+(P3S%PS>0);
    TF=P1F+P2F+P3F;
    if(TF>RF)
    {
        int dif=2;
        while(TF-RF>=dif)
        {
            if(P1F>0)
            {
            v1.push_back(RF);
            visit1[RF]=1;
            P1F--;

            }
            if(P2F>0)
            {
                visit2[RF]=1;
            v2.push_back(RF);
            P2F--;

            }
            if(P3F>0)
            {
            v3.push_back(RF);
            visit3[RF]=1;
            P3F--;
            }
            shared.push_back(RF);
            RF--;
            TF=P1F+P2F+P3F;
            if(P1F==0||P2F==0||P3F==0)
                dif=1;

        }
        if(TF>RF)
        {
            v2.push_back(RF);
            visit2[RF]=1;
            v3.push_back(RF);
            visit3[RF]=1;
            shared.push_back(RF);
            RF--;
            P2F--;
            P3F--;
        }
        while(P3F--)
        {
            v3.push_back(RF--);
        }
        while(P2F--)
        {
            v2.push_back(RF--);
        }
        while(P1F--)
        {
            v1.push_back(RF--);
        }


    }
    else
    {
        while(P3F--)
            v3.push_back(RF--);
        while(P2F--)
            v2.push_back(RF--);
        while(P1F--)
            v1.push_back(RF--);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());
    sort(shared.begin(),shared.end());
    printf("Page Table for P1:\n");
    for(i=0;i<v1.size();i++)
        printf("    %2d |%2d|\n       ----\n",i,v1[i]-1);

    printf("Page Table for P2:\n");
    for(i=0;i<v2.size();i++)
        printf("    %2d |%2d|\n       ----\n",i,v2[i]-1);


    printf("Page Table for P3:\n");
    for(i=0;i<v3.size();i++)
        printf("    %2d |%2d|\n       ----\n",i,v3[i]-1);
    printf("\nNumber of shared Frame: %d\n",shared.size());
    printf("\nDescription of shared Frame:\n");
    for(i=0;i<shared.size();i++)
    {
        printf("Frame %2d is shared by",shared[i]);
        if(visit1[shared[i]])
            printf(" P1");
        if(visit2[shared[i]])
            printf(" P2");
        if(visit3[shared[i]])
            printf(" P3");
        printf("\n");
    }
    return 0;
}
