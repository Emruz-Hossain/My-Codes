#include<bits/stdc++.h>
using namespace std;

set<char>Op,Op_lib;
set<string>Key,Var,Num,Func,Key_lib;
vector<string>tokens;
void tokenize(string ss)
{
  string sp="";
  reverse(ss.begin(),ss.end());
  while(ss.size()>0)
  {
      char ch=ss.back();
      ss.pop_back();
      //printf("%c\n",ch);
      if(ch=='(')
      {
          sp+=ch;
          while(ch!=')')
          {
              ch=ss.back();
              ss.pop_back();
              sp+=ch;
          }
          Func.insert(sp);
          sp="";
      }
      else if(Op_lib.find(ch)!=Op_lib.end())
      {
          if(sp.size()>0)
            tokens.push_back(sp);
          Op.insert(ch);
          sp="";
      }
      else if(ch==' ')
      {
          if(sp.size()>0)
            tokens.push_back(sp);
          sp="";
      }
      else
        sp+=ch;


  }
}
bool keyword(string ss)
{
    if(Key_lib.find(ss)!=Key_lib.end())
        return true;
    else
        return false;
}
bool number(string ss)
{
    int i;
    for(i=0;i<ss.size();i++)
    {
        if(!(ss[i]>='0'&&ss[i]<='9'))
            return false;
    }
    return true;
}

int main()
{
   int i;
   Key_lib.insert({"int","double","if","else","return"});
   Op_lib.insert({'+','-','*','/','=',',',';','{','}'});
   string ss;
   getline(cin,ss);
   tokenize(ss);
   for(i=0;i<tokens.size();i++)
   {
       if(keyword(tokens[i]))
       {
           Key.insert(tokens[i]);
       }
       else if(number(tokens[i]))
       {
           Num.insert(tokens[i]);
       }
       else
         Var.insert(tokens[i]);
   }
   cout<<"Keywords:"<<endl;
   for(auto it:Key)
    cout<<it<<" ";
   cout<<endl<<endl<<"Function:"<<endl;
   for(auto it:Func)
    cout<<it<<" ";
   cout<<endl<<endl<<"Operators:"<<endl;
   for(auto it:Op)
    cout<<it<<" ";
   cout<<endl<<endl<<"Variables:"<<endl;
   for(auto it:Var)
    cout<<it<<" ";
   cout<<endl<<endl<<"Numbers:"<<endl;
   for(auto it:Num)
    cout<<it<<" ";

}
