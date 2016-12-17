#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string>
#include<ctype.h>
#include<string.h>
#include<sstream>
#include<fstream>
#define sz 1000000
using namespace std;
string name,birth_date,adrs,date,month,year,uid,line,idd,ssalary,uadrs,sname,usal;
int id,salary;
int main()
{
    int i,cnt;
    ofstream data;
    data.open("Data.txt");
    srand(time(NULL));
    string districts[100]={"Barguna","Barisal","Jhalokati","Patuakhali","Pirojpur","Bandarban","Brahmanbaria","Chandpur","Chittagong","Comilla","Cox's Bazar","Feni","Khagrachhari","Lakshmipur","Noakhali","Rangamati","Dhaka","Faridpur","Gazipur","Gopalganj","Jamalpur","Kishoreganj","Madaripur","Manikganj","Munshiganj","Mymensingh","Narayanganj","Narsingdi","Netrakona","Rajbari","Shariatpur","Sherpur","Tangail","Bagerhat","Chuadanga","Jessore","Jhenaidah","Khulna","Kushtia","Magura","Meherpur","Narail","Satkhira","Bogra","Joypurhat","Naogaon","Natore","Nawabganj","Pabna","Sirajganj","Dinajpur","Gaibandha","Kurigram","Lalmonirhat","Nilphamari","Panchagarh","Rangpur","Thakurgaon","Habiganj","Moulvibazar","Sunamganj","Sylhet"};
    string prefix[10]={"M.A ","Mohammad ","S.M ","Abdur ","A.R ","Mohammad ","Abu ","T.I ","Abdur ","K.M "};
    string suffix[20]={" Hossain"," Rahman"," Khan"," Siddiq"," Ali"," Miah"," Shekh"," Sharkar"," Islam"," Chaudury"};
    string first[40]={"Ja","Ru","Ra","Ka","Fa","Sa","Sa","Ha","Na","Ba","Ta","Ma","Shah","Wa","Se","A","Kha","Ya","Yu","Mo","Za","Ga","Si"};
    string last[40]={"bel","sel","lim","rim","him","heen","bin","fiq","rukh","sem","hid","run","ruf","rif","liq","sin","suf","sem","nim","dud","ful","qul","bir","kir","med","hed","sum"};
    for(i=0;i<5000;i++)
    {
         name=prefix[rand()%10]+first[rand()%23]+last[rand()%27]+suffix[rand()%10];
         id=i+1;
         salary=rand()%50000;
             stringstream ss; ss<<rand()%29+1;
            date=ss.str();
            stringstream ss1;ss1<<rand()%12+1;
            month=ss1.str();
            stringstream ss2;ss2<<1950+rand()%34;
            year=ss2.str();
            birth_date=date+"-"+month+"-"+year;
          adrs=districts[rand()%62];
         data<<id<<endl<<name<<endl<<birth_date<<endl<<adrs<<endl<<salary<<endl<<"----------"<<endl;
    }
    int r=i+1;
    data.close();
    int k=1;
    while(k!=5)
    {   system("CLS");
         cout<<"Chose Your option:"<<endl<<"1. Search"<<endl<<"2. Add data"<<endl<<"3. Delet data"<<endl<<"4. Update data"<<endl<<"5.Exit"<<endl;
         cin>>k;
         if(k==1)
         {
             k=0;
             int s;
             system("CLS");
             cout<<"Chose your search option:"<<endl<<"1. Search by id."<<endl<<"2. Search by name."<<endl<<"3. Search by salary."<<endl<<"4. Search by address."<<endl<<"5. Back to main menu."<<endl;
             cin>>s;
             if(s==1)
             {
                 system("CLS");
                 cout<<"Enter Id number:"<<endl;
                 cin>>uid;
                 ifstream file("data.txt");
                 int iid=0;
                 while(!file.eof())
                 {
                     getline(file,idd);
                     iid++;
                     if(idd==uid)
                     {
                         getline(file,name);
                         if(name=="Data removed.")
                         {
                            cout<<"This Data has been removed"<<endl;
                            break;
                         }
                         getline(file,birth_date);
                         getline(file,adrs);
                         getline(file,ssalary);
                          cout<<endl<<"ID NO:     "<<iid<<endl<<"Name:      "<<name<<endl<<"Birth day: "<<birth_date<<endl<<"Address:   "<<adrs<<endl<<"Salary:    "<<salary<<endl<<"----------"<<endl;
                          break;
                     }
                     getline(file,line);
                     if(line=="Data removed.")
                     {
                         getline(file,line);
                          continue;
                     }
                     getline(file,line);
                     getline(file,line);
                     getline(file,line);
                     getline(file,line);
                 }
                 file.close();
             }
             if(s==2)
             {
               system("CLS");
                 cout<<"Enter Name:"<<endl;
                 cin>>sname;
                 int l=sname.size();
                 ifstream file("data.txt");
                  ofstream out;
                out.open("outp.txt");
                 while(!file.eof())
                 {
                     getline(file,idd);
                     getline(file,name);
                     if(name=="Data removed.")
                     {
                         getline(file,line);
                          continue;
                     }
                     string sub;
                     for(int i=0;i<l;i++)
                     sub=sub+name[i];
                     if(sname==sub)
                     {
                         getline(file,birth_date);
                         getline(file,adrs);
                         getline(file,ssalary);
                         cout<<endl<<idd<<"  "<<name<<"  "<<birth_date<<"   "<<adrs<<"     "<<ssalary<<endl;
                          getline(file,line);
                          continue;
                     }
                      getline(file,line);
                     getline(file,line);
                     getline(file,line);
                      getline(file,line);
                 }
                 file.close();
             }
             if(s==3)
             {
                 system("CLS");
                 cout<<"Enter Salary scale:"<<endl;
                 cin>>usal; char ch;
                 string usalary;
                 ifstream file("data.txt");
                  ofstream out;
                out.open("outp.txt");
                ch=usal[0];
                for(i=1;i<usal.size();i++)
                    usalary+=usal[i];
                 while(!file.eof())
                 {
                     getline(file,idd);
                     getline(file,name);
                     if(name=="Data removed.")
                     {
                         getline(file,line);
                          continue;
                     }
                     getline(file,birth_date);
                     getline(file,adrs);
                    getline(file,ssalary);
                    int pp,qq;
                    istringstream (ssalary) >> pp;
                    istringstream (usalary) >> qq;
                     if(ch=='='&&pp==qq)
                     {
                         cout<<endl<<"ID NO:     "<<idd<<endl<<"Name:      "<<name<<endl<<"Birth day: "<<birth_date<<endl<<"Address:   "<<adrs<<endl<<"Salary:    "<<ssalary<<endl<<"----------"<<endl;
                          getline(file,line);
                          continue;
                     }
                   else  if(ch=='>'&&pp>qq)
                     {
                         cout<<endl<<"ID NO:     "<<idd<<endl<<"Name:      "<<name<<endl<<"Birth day: "<<birth_date<<endl<<"Address:   "<<adrs<<endl<<"Salary:    "<<ssalary<<endl<<"----------"<<endl;
                          getline(file,line);
                          continue;
                     }
                    else if(ch=='<'&&pp<qq)
                     {
                         cout<<endl<<"ID NO:     "<<idd<<endl<<"Name:      "<<name<<endl<<"Birth day: "<<birth_date<<endl<<"Address:   "<<adrs<<endl<<"Salary:    "<<ssalary<<endl<<"----------"<<endl;
                          getline(file,line);
                          continue;
                     }
                     getline(file,line);
                 }
                 file.close();
             }
             if(s==4)
             {
                system("CLS");
                 cout<<"Enter Address:"<<endl;
                 cin>>uadrs;
                 ifstream file("data.txt");
                  ofstream out;
                out.open("outp.txt");
                 while(!file.eof())
                 {
                     getline(file,idd);
                     getline(file,name);
                     if(name=="Data removed.")
                     {
                         getline(file,line);
                          continue;
                     }
                     getline(file,birth_date);
                     getline(file,adrs);
                     if(adrs==uadrs)
                     {
                         getline(file,ssalary);
                         cout<<endl<<"ID NO:     "<<idd<<endl<<"Name:      "<<name<<endl<<"Birth day: "<<birth_date<<endl<<"Address:   "<<adrs<<endl<<"Salary:    "<<ssalary<<endl<<"----------"<<endl;
                          getline(file,line);
                          continue;
                     }
                     getline(file,line);
                     getline(file,line);
                 }
                 file.close();
             }
             if(s==5)
                continue;
             system("pause");
         }
         else if(k==2)
         {
             ifstream file("data.txt");
             ofstream temp("temp.txt");
             cout<<"Enter name:"<<endl;
             cin>>name;
             cout<<"Enter Birth_date:"<<endl;
             cin>>birth_date;
             cout<<"Enter Address:"<<endl;
             cin>>adrs;
             cout<<"Enter Salary:"<<endl;
             cin>>salary;
             while(!file.eof())
             {
                getline(file,line);
                temp<<line<<endl;
             }
             temp<<r<<endl<<name<<endl<<birth_date<<endl<<adrs<<endl<<salary<<endl<<"----------"<<endl;
             file.clear();
             file.seekg(0,ios::beg);
             file.close();
             temp.close();
             remove("data.txt");
             rename("temp.txt","data.txt");
             cout<<"\nData successfully added to file\n"<<endl;
             r++;
             system("pause");
         }
         else if(k==3)
         {
            cout<<"Enter the ID whose data you want to delet:"<<endl;
             cin>>uid;
             ifstream file("data.txt");
             ofstream temp("temp.txt");
             cnt=0;
            int p=0;
             while(!file.eof())
             {
                getline(file,line);
                if(p==0)
                temp<<line<<endl;
                 if(p!=0)
                     p++;
                 if(p==5)
                    p=0;
                 if(line==uid)
                 {
                     p=1;
                     temp<<"Data removed."<<endl;
                 }
                 cnt++;
             }
             file.clear();
             file.seekg(0,ios::beg);
             file.close();
             temp.close();
             remove("data.txt");
             rename("temp.txt","data.txt");
             cout<<"File successfully delet."<<endl;
             system("pause");
         }
         else if(k==4)
         {
             system("CLS");
             long long pos;
             cout<<"Enter the ID whose data you want to update:"<<endl;
             cin>>uid;
             ifstream file("data.txt");
             ofstream temp("temp.txt");
             cnt=0;
            int p=0;
             while(!file.eof())
             {
                getline(file,line);
                if(p==0)
                temp<<line<<endl;
                 if(p!=0)
                     p++;
                 if(p==5)
                    p=0;
                 if(line==uid)
                 {
                     p=1;
                     cout<<"Enter Name:"<<endl;
                     cin>>name;
                     temp<<name<<endl;
                     cout<<"Enter Birth date:"<<endl;
                     cin>>birth_date;
                     temp<<birth_date<<endl;
                     cout<<"Enter Address:"<<endl;
                     cin>>adrs;
                     temp<<adrs<<endl;
                     cout<<"Enter Salary:"<<endl;
                     cin>>salary;
                     temp<<salary<<endl;
                     line="";
                 }
                 cnt++;
             }
             file.clear();
             file.seekg(0,ios::beg);
             file.close();
             temp.close();
             remove("data.txt");
             rename("temp.txt","data.txt");
             cout<<"File successfully updated."<<endl;
             system("pause");
         }
         else if (k==5)
            break;
    }
    return 0;
}
