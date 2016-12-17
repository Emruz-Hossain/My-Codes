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
using namespace std;
#define inf 1<<25
#define sz 200
map<char ,char>mp;
string rev(string s)
{
   char rs[100];
    int i,x=0;
    for(i=s.size()-1;i>=0;i--)
        rs[x++]=s[i];
    rs[x]='\0';
    return rs;
}
int miror(string s)
{
    string rs,ss;
    ss=s;
    int i;
    for(i=0;i<s.size();i++)
    {
        if(mp[s[i]]!=0)
            s[i]=mp[s[i]];
        else
            return 0;
    }
    rs=rev(s);
    if(ss==rs)
        return 1;
    else
        return 0;
}
int main()
{
    string str,ss,rs;
    while((cin>>str))
    {
    mp.clear();
    mp['A']='A';mp['E']='3';mp['H']='H';mp['I']='I';mp['J']='L';mp['L']='J';mp['M']='M';mp['O']='O';mp['S']='2';mp['T']='T';mp['U']='U';mp['V']='V';
    mp['W']='W';mp['X']='X';mp['Y']='Y';mp['Z']='5';mp['1']='1';mp['2']='S';mp['3']='E';mp['5']='Z';mp['8']='8';
    int m=miror(str);
    rs=rev(str);
    int p=0;
    if(rs==str)
        p=1;
    if(p==1&&m==1)
    {
        cout<<str<<" -- is a mirrored palindrome."<<endl;
    }
    else if(p==1)
        cout<<str<<" -- is a regular palindrome."<<endl;
    else if(m==1)
        cout<<str<<" -- is a mirrored string."<<endl;
    else
        cout<<str<<" -- is not a palindrome."<<endl;
    cout<<endl;
    }

    return 0;
}


