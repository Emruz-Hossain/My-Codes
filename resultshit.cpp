#include<stdio.h>
#include<algorithm>
using namespace std;
struct student_info
{
    char Name[20];
    int Math,English,Science,Total;
};
student_info ar[100];
bool cmp(student_info a,student_info b)
{
    if(a.Total>=b.Total)
        return true;
    else
        return false;
}
int main()
{
    int i,n;
    printf("Enter Number of Students:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Name, number of Math, English and Science of %d th student:\n",i);
        scanf("%s %d %d %d",&ar[i].Name,&ar[i].Math,&ar[i].English,&ar[i].Science);
    }
    for(i=0;i<n;i++)
        ar[i].Total=ar[i].Math+ar[i].English+ar[i].Science;
    sort(ar,ar+n,cmp);
    printf("\nResult Shit:\n");
    printf("Serial   Name    Math    English    Science    Total\n");
    printf("--------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        printf("%d %12s %5d %7d %10d %12d\n",i,ar[i].Name,ar[i].Math,ar[i].English,ar[i].Science,ar[i].Total);
    }
    return 0;
}
