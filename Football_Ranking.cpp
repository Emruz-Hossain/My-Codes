//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
struct st
{
    int match,won,lose,draw,point;
    string head_to_head,team_name;
};
st aray[50];
map<string,map<string,string> >mp;
bool cmp(st a,st b)
{
    if(a.point>b.point)
        return true;
    else if(a.point<b.point)
        return false;
    else
    {
        if(mp[a.team_name][b.team_name]==a.team_name)
            return true;
        else if(mp[a.team_name][b.team_name]==b.team_name)
            return false;
        else
        {
            if(a.won>b.won)
                return true;
            else if(a.won<b.won)
                return false;
            else
            {
                if(a.lose<b.lose)
                    return true;
                else
                    return false;
            }
        }
    }
}
int main()
{
    int team_no,i,j,m,n;
    cout<<"Enter Number Of Team:"<<endl;
    cin>>team_no;
    cout<<endl<<"Enter Team Name:"<<endl<<endl;
    for(i=0;i<team_no;i++)
    {
        cin>>aray[i].team_name;
        aray[i].match=0;
        aray[i].draw=0;
        aray[i].lose=0;
        aray[i].point=0;
        aray[i].won=0;

    }
    cout<<endl;
    cout<<"Enter match result:"<<endl;
    for(i=0;i<team_no-1;i++)
    {
        for(j=i+1;j<team_no;j++)
        {
            cout<<endl<<aray[i].team_name<<"  Vs  "<<aray[j].team_name<<endl;
            cin>>m>>n;
            aray[i].match++;
            aray[j].match++;
            if(m>n)
            {
                aray[i].won++;
                aray[j].lose++;
                aray[i].point+=3;
                mp[aray[i].team_name][aray[j].team_name]=mp[aray[j].team_name][aray[i].team_name]=aray[i].team_name;
            }
            else if(m<n)
            {
                aray[i].lose++;
                aray[j].won++;
                aray[j].point+=3;
                mp[aray[i].team_name][aray[j].team_name]=mp[aray[j].team_name][aray[i].team_name]=aray[j].team_name;
            }
            else
            {
                aray[i].draw++;
                aray[j].draw++;
                aray[i].point++;
                aray[j].point++;
                mp[aray[i].team_name][aray[j].team_name]=mp[aray[j].team_name][aray[i].team_name]="draw";
            }

        }
    }
    sort(aray,aray+team_no,cmp);
    cout<<endl;
    cout<<"Rank"<<setw(18)<<"Team name"<<setw(15)<<"Total match"<<setw(8)<<"Won"<<setw(8)<<"Lose"<<setw(8)<<"Draw"<<setw(8)<<"Point"<<endl;
    cout<<endl;
    for(i=0;i<team_no;i++)
    {
        cout<<i+1<<setw(20)<<aray[i].team_name<<setw(10)<<aray[i].match<<setw(13)<<aray[i].won<<setw(8)<<aray[i].lose<<setw(8)<<aray[i].draw<<setw(8)<<aray[i].point<<endl;
        cout<<endl;
    }
}

