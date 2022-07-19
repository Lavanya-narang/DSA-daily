#include <bits/stdc++.h>
using namespace std;
int operation(int v1,int v2,char ch)
{
    if(ch=='*')
    {
        return v1*v2;
    }
    else if(ch=='/')
    {
        return v1/v2;
    }
    else if(ch=='+')
    {
        return v1+v2;
    }
    else if(ch=='-')
    {
        return v1-v2;
    }
    else
    {
        return 0;
    }
}
int main() {
  string exp;
  cin >> exp;

  // write yout code here
stack<int>value;
  stack<string>infix;
  stack<string>prefix;
  for(int i=exp.length()-1;i>=0;i--)
  {
      char ch=exp[i];
      if(ch=='+' ||  ch=='*' || ch=='-' || ch=='/')
      {
          stringstream ss;
          string s;
          ss<<ch;
          ss>>s;
          int v1=value.top();
          value.pop();
          int v2=value.top();
          value.pop();
          int val=operation(v1,v2,ch);
          value.push(val);
          
          string iv1=infix.top();
          infix.pop();
          string iv2=infix.top();
          infix.pop();
          string ival="("+iv1+s+iv2+")";
          infix.push(ival);
          
          string pv1=prefix.top();
          prefix.pop();
          string pv2=prefix.top();
          prefix.pop();
          string val2=pv1+pv2+s;
          prefix.push(val2);
      }
      else
      {
          value.push(ch-'0');
          stringstream ss;
          string s;
          ss<<ch;
          ss>>s;
          infix.push(s);
          prefix.push(s);
      }
  }
  cout<<value.top()<<endl;
  value.pop();
  cout<<infix.top()<<endl;
  value.pop();
  cout<<prefix.top()<<endl;
  value.pop();
  return 0;
}
