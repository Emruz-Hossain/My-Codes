#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
struct Footbal
{
    int point,win,tie,loss,gdiff,gscored,gagainst,nofmatch;
    string team_name,team_name1;
};
bool cmp(Footbal a, Footbal b)
{
    if(a.point>b.point) return true;
    else if(a.point<b.point) return false;
    else if(a.win>b.win) return true;
    else if(a.win<b.win) return false;
    else if(a.gdiff>b.gdiff) return true;
    else if(a.gdiff<b.gdiff) return false;
    else if(a.gscored>b.gscored) return true;
    else if(a.gscored<b.gscored) return false;
    else if(a.nofmatch<b.nofmatch) return true;
    else if(a.nofmatch>b.nofmatch) return false;
    else if(a.team_name<b.team_name) return true;
    else return false;
}
int main()
{
    int T;
    cin>>T;
    //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    char m=getchar();
    while(T--){

        string Tournament_name;
        getline(cin,Tournament_name);
        int n_t,n_m;
        cin>>n_t;
        Footbal Teams[n_t];
        for(int i=0;i<n_t;i++){
            Teams[i].point=0; Teams[i].win=0; Teams[i].tie=0; Teams[i].loss=0;
            Teams[i].gdiff=0; Teams[i].gscored=0; Teams[i].gagainst=0; Teams[i].nofmatch=0;
        }
        m=getchar();
        string str;
        for(int i=0;i<n_t;i++){
            getline(cin,str);
            Teams[i].team_name1=str;
            transform(str.begin(), str.end(), str.begin(),(int (*)(int))tolower);
            Teams[i].team_name=str;
        }
        cin>>n_m;
        string match;
        int n1,n2;
        m=getchar();
        for(int i=0;i<n_m;i++){
            getline(cin,match);
            transform(match.begin(), match.end(), match.begin(),(int (*)(int))tolower);
            int j,k,l;
            string s1,s2;
            for(j=0;match[j]!='#';j++)
                s1+=match[j];
            for(k=0;k<n_t;k++){
                if(s1==Teams[k].team_name) break;
            }
            n1=0;n2=0;
            for(l=j+1;match[l]!='@';l++)
                n1=n1*10+(match[l]-'0');
            for(l=l+1;match[l]!='#';l++)
                n2=n2*10+(match[l]-'0');
            for(l=l+1;match[l]!='\0';l++)
                s2+=match[l];
            for(l=0;l<n_t;l++){
                if(s2==Teams[l].team_name) break;
            }
            Teams[k].gscored+=n1; Teams[l].gscored+=n2;
            Teams[k].gagainst+=n2; Teams[l].gagainst+=n1;
            Teams[k].gdiff+=(n1-n2); Teams[l].gdiff+=(n2-n1);
            Teams[k].nofmatch++; Teams[l].nofmatch++;
            if(n1>n2){
                Teams[k].win++;
                Teams[l].loss++;
                Teams[k].point+=3;
            }
            else if(n2>n1){
                Teams[l].win++;
                Teams[k].loss++;
                Teams[l].point+=3;
            }
            else{
                Teams[k].tie++;
                Teams[l].tie++;
                Teams[k].point++;
                Teams[l].point++;
            }
        }
        sort(Teams,Teams+n_t,cmp);
        cout<<Tournament_name<<endl;
        for(int i=0;i<n_t;i++){
            cout<<i+1<<") "<<Teams[i].team_name1;
            printf("%dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",Teams[i].point,Teams[i].nofmatch,Teams[i].win,Teams[i].tie,Teams[i].loss,Teams[i].gdiff,Teams[i].gscored,Teams[i].gagainst);
        }
        if(T!=0) cout<<endl;
    }
    return 0;
}
