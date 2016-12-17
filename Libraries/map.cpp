//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;
map<int,int>ii;
map<string,int>si;
map<string,string>ss;
int main()
{
    ss["abc"]="def";
    si["xyz"]=1;
    ii[1000000000]=2000;
    cout<<ss["abc"]<<" "<<si["xyz"]<<" "<<ii[1000000000]<<endl;
}
