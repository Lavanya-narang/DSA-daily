#include <bits/stdc++.h>
using namespace std;
bool balancedbrac(stack<char>
&st,char cha)
{
    if(st.size()==0 || st.top()!=cha )
    {
        return false;
    }
    else
    {
        st.pop();
        return true;
    }
}
int main(int argc, char** argv)
{
  string str;
  getline(cin,str);
  stack<char>stack;
  
  for(int i=0;i<str.length();i++)
  {
      char ch=str[i];
      if(ch=='[' || ch=='{' || ch=='(')
      {
          stack.push(ch);
      }
      else if(ch==')')
      {
          bool val=balancedbrac(stack,'(');
          if(val==false)
          {
              cout<<"false";
              return 0;
          }
      }
     
     
      else if(ch=='}')
      {
          bool val=balancedbrac(stack,'{');
          if(val==false)
          {
              cout<<"false";
              return 0;
          } 
      }
     
        else if(ch==']')
      {
          bool val=balancedbrac(stack,'[');
          if(val==false)
          {
              cout<<"false";
            return 0;  
          } 
      }
  }
  if(stack.size
  ()==0)
  {
      cout<<"true";
  }
  else{
      cout<<"false";
  }
  return 0;
}
