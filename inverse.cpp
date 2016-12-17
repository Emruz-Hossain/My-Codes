#include<iostream>
using namespace std;
int main()
{
cout<<"Student Name: MD: ASIFUR RAHMAN"<<endl;
cout<<"Student ID: 1201120"<<endl;
float a[3][3],b[3][3],c[3][3],d[3][3],rowA,colA,rowB,colB,rowC,colC,rowD,colD;
float det=0;
int i,j;
cout<<"Matrix a:"<<endl;
cout<<"Number of row = ";cin>>rowA;
cout<<"Number of column = ";cin>>colA;
cout<<"Enter the elements of matrix a: \n"<<endl;
for(i=0;i<rowA;i++)
{
for(j=0;j<colA;j++)
{
cin>>a[i][j];
}
cout<<"\n";
}
cout<<"Matrix a: \n"<<endl;
for(i=0;i<rowA;i++)
{
for(j=0;j<colA;j++)
{
cout<<"\t"<<a[i][j];
}
cout<<"\n";
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
b[i][j]=a[j][i];
}
cout<<"\n";
}
for(i=0;i<3;i++)
{
det = det + (b[0][i]*(b[1][(i+1)%3]*b[2][(i+2)%3] - b[1][(i+2)%3]*b[2][(i+1)%3]));
}
if(det==0)
{
cout<<"\nInverse of this matrix doesn't exist."<<endl;
}
else
{
cout<<"Inverse of matrix is: \n";
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
cout<<((b[(i+1)%3][(j+1)%3] * b[(i+2)%3][(j+2)%3]) - (b[(i+1)%3][(j+2)%3]*b[(i+2)%3][(j+1)%3]))/det<<"\t";
c[i][j]=((b[(i+1)%3][(j+1)%3] * b[(i+2)%3][(j+2)%3]) - (b[(i+1)%3][(j+2)%3]*b[(i+2)%3][(j+1)%3]))/det;
cout<<"\t";
}
cout<<"\n";
}
}
rowC=rowA;
colC=colA;
 if(colA!=rowC)
 {
cout<<"\nMultiplication of A and C matrix isn't possible.\n";
}
 else{for(i=0;i<rowC;i++)
 {
for(j=0;j<colC;j++)
{
d[i][j]=0;
for(int k=0;k<rowC;k++)
{
d[i][j]=d[i][j]+(a[i][k]*c[k][j]);
}
}
}
cout<<"\nAfter multiplication the new matrix is: \n"<<endl;
for(i=0;i<rowC;i++)
{
for(j=0;j<colC;j++)
{
cout<<"\t"<<(int)d[i][j];
}
cout<<"\n";
}
}
}



