//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string>
#include<ctype.h>
#include<string.h>
#include<sstream>
#include<fstream>
#define sz 100

using namespace std;
int main()
{

    //    freopen("output.txt","w",stdout);
    //    freopen("input.txt","r",stdin);
    int n,id,i;
    string name,depertment,level,term,tag,str;
   string iid,nname,ddept,llev,tterm;
    string first[40]={"Ja","Ru","Ra","Ka","Fa","Sa","Sa","Ha","Na","Ba","Ta","Ma","Shah","Wa","Se","A","Kha","Ya","Yu","Mo","Za","Ga","Si"};
    string last[40]={"bel","sel","lim","rim","him","heen","bin","fiq","rukh","sem","hid","run","ruf","rif","liq","sin","suf","sem","nim","dud","ful","qul","bir","kir","med","hed","sum"};
    string suffix[20]={" Hossain"," Rahman"," Khan"," Siddiq"," Ali"," Miah"," Shekh"," Sharkar"," Islam"," Chaudury"};
    string lev[20]={"L-1","L-2","L-3","L-4"};
    string ter[40]={"T-1","T-2"};
    string dept[20]={"EEE","CSE","CIVIL","ETE","ME","PME","ARC","URP"};
    ofstream mdata;
    mdata.open("Main data.txt");
    srand(time(NULL));
    cout<<"How many data you want to generate:"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
    name=first[rand()%23]+last[rand()%27]+suffix[rand()%10];
    depertment=dept[rand()%8];
    level=lev[rand()%4];
    term=ter[rand()%2];
    id=100000+rand()%10000;
    mdata<<id<<" "<<name<<" "<<depertment<<" "<<level<<" "<<term<<endl;
    }
    mdata.close();
    cout<<"Enter your search tag:"<<endl;
    cin>>tag;
    if(tag=="name")
    {
         ifstream file("Main data.txt");
                 int iid=0,x=0,p=0,k,l;
                 while(!file.eof())
                 {
                     string ss;
                     getline(file,str);
                     for(k=0;k<str.size();k++)
                     {

                         if(str[k]==' ')
                            break;
                     }
                     for(l=k+1;l<str.size();l++)
                     {
                         if(str[l]==' ')
                            break;
                         ss+=str[l];
                     }
                     cout<<ss<<endl;
                 }
                 file.close();
    }
    else if(tag=="dept")
    {
        ifstream file("Main data.txt");
                 int iid=0,x=0,p=0,k,l,m;
                 while(!file.eof())
                 {
                     string ss;
                     getline(file,str);
                     for(k=0;k<str.size();k++)
                     {

                         if(str[k]==' ')
                            break;
                     }
                     for(l=k+1;l<str.size();l++)
                     {
                         if(str[l]==' ')
                            break;
                     }
                     for(m=l+1;l<str.size();m++)
                     {
                         if(str[m]==' ')
                            break;
                            ss+=str[m];
                     }
                     cout<<ss<<endl;
                 }
                 file.close();
    }
    else if(tag=="id")
    {
        ifstream file("Main data.txt");
                 int iid=0,x=0,p=0,k;
                 while(!file.eof())
                 {
                     string ss;
                     getline(file,str);
                     for(k=0;k<str.size();k++)
                     {

                         if(str[k]==' ')
                            break;
                         ss+=str[k];
                     }
                     cout<<ss<<endl;
                 }
                 file.close();
    }
    else if(tag=="level")
    {
      ifstream file("Main data.txt");
                 int iid=0,x=0,p=0,k,l,m,q;
                 while(!file.eof())
                 {
                     string ss;
                     getline(file,str);
                     for(k=0;k<str.size();k++)
                     {

                         if(str[k]==' ')
                            break;
                     }
                     for(l=k+1;l<str.size();l++)
                     {
                         if(str[l]==' ')
                            break;
                     }
                     for(m=l+1;m<str.size();m++)
                     {
                         if(str[m]==' ')
                            break;

                     }
                     for(p=m+1;p<str.size();p++)
                     {
                         if(str[p]==' ')
                            break;

                     }
                     for(q=p+1;q<str.size();q++)
                     {
                         if(str[q]==' ')
                            break;
                            ss+=str[q];

                     }
                     cout<<ss<<endl;
                 }
                 file.close();
    }
    else if(tag=="term")
    {
        ifstream file("Main data.txt");
                 int iid=0,x=0,p=0,k,l,m,q,r;
                 while(!file.eof())
                 {
                     string ss;
                     getline(file,str);
                     for(k=0;k<str.size();k++)
                     {

                         if(str[k]==' ')
                            break;
                     }
                     for(l=k+1;l<str.size();l++)
                     {
                         if(str[l]==' ')
                            break;
                     }
                     for(m=l+1;m<str.size();m++)
                     {
                         if(str[m]==' ')
                            break;

                     }
                     for(p=m+1;p<str.size();p++)
                     {
                         if(str[p]==' ')
                            break;

                     }
                     for(q=p+1;q<str.size();q++)
                     {
                         if(str[q]==' ')
                            break;

                     }
                     for(r=q+1;r<str.size();r++)
                     {
                         if(str[r]==' ')
                            break;
                            ss+=str[r];

                     }

                     cout<<ss<<endl;
                 }
                 file.close();
    }
    return 0;
}

