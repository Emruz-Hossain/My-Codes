
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<iostream>
#include<iomanip>
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))
#define PB(x) push_back(x)
#define SZ(a) a.size()
#define len(a) strlen(a)

#define inf 1<<25
#define sz 2000
#define eps 1e-9
#define mod  1000000007
 int gcd(int a, int b) { return (b != 0 ? gcd(b, a%b) : a);}
int lcm(int a, int b) { return (a / gcd(a, b) * b);}

int R[]={1,-1,0,0,1,-1,-1,1};
int C[]={0,0,1,-1,1,-1,1,-1};
int KR[]={-2,-2,-1,1,2,2,-1,1};
int KC[]={1,-1,2,2,1,-1,-2,-2};
int bst[10000];
vector<int>v;
void Insert(int ind,int p)
{
    if(bst[ind]==-1)
    {
        bst[ind]=p;
        return;
    }
    else if(p>=bst[ind])
    {
        Insert(2*ind+1,p);
    }
    else
    {
        Insert(2*ind,p);
    }
    return;
}
int Find(int ind,int p)
{
    if(bst[ind]==-1)
        return -1;
    else if(bst[ind]==p)
    {
        return ind;
    }
    else if(p>bst[ind])
    {
        return Find(2*ind+1,p);
    }
    else
        return Find(ind*2,p);
}
 void TIE(void)
{
    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
   int a,b,c,d,m,n,p,x,i,j,q,r,l,opt,maxx=0,ind;
    system("cls");
    printf("Chose Your Operation in Binary Search tree:\n1.Insert Ellement.\n2.Delet Element.\n3.Serch Element.\n4.View the tree.\n5.Exit.\n");
    scanf("%d",&opt);
    maxx=10000;
    if(opt==1)
    {
        printf("Enter number of Elements you that want to insert:\n");
        scanf("%d",&n);

        printf("Enter elements:\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&p);
            Insert(1,p);
        }
        printf("\nInsertion Complete.\n\n");
        system("pause");
        TIE();
    }
    else if(opt==2)
    {
        printf("Enter the number you want to delet.\n");
        scanf("%d",&p);
        ind=Find(1,p);
        if(ind==-1)
            printf("\nInvalid Delet operation.The number is not in the tree.\n\n");
        else
        {
            v.clear();
            bst[ind]=-1;
            for(i=ind;i<maxx;i++)
            {
                if(bst[i]!=-1)
                {
                    v.push_back(bst[i]);
                    bst[i]=-1;
                }

            }
            for(i=0;i<v.size();i++)
                Insert(1,v[i]);

            printf("\nDelet Completed.\n\n");
        }
        system("pause");
        TIE();
    }
    else if(opt==3)
    {
        printf("Enter number that you want to serch:\n");
        scanf("%d",&p);
        ind=Find(1,p);
        if(ind==-1)
            printf("\nNumber not Found.\n\n");
        else
            printf("\nNumber Found at %d th location of the tree.\n\n",ind);
        system("pause");
        TIE();
    }
    else if(opt==4)
    {
        for(i=0;i<maxx;i++)
          {
              if(bst[i]!=-1)
              {
              printf("Root:%d   ",bst[i]);
              if(bst[i*2]==-1)
                  printf("Left: No left Child ");
              else
                printf("Left: %d             ",bst[i*2]);
              if(bst[i*2+1]==-1)
                printf("Right: No right child\n");
              else
                printf("Right: %d\n",bst[i*2+1]);
              }

          }
        printf("\n");
        system("pause");
        TIE();
    }
    else
        return;

    return;
}
int main()
{
    memset(bst,-1,sizeof(bst));
    TIE();
    return 0;
}
