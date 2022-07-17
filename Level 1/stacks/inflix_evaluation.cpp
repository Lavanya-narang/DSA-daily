#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;
int pre(char ch)
{
    if(ch=='*')
    {
        return 2;
    }
    else if(ch=='/')
    {
        return 2;
    }
    else if(ch=='+')
    {
        return 1;
    }
    else
    {
        return 1;
    }
}
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
    else
    {
        return v1-v2;
    }
}
int main() {
  string str;
  getline(cin, str);
  // write your code here
    stack<int>is;
    stack<char>cs;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(isdigit(ch))
        {
            is.push(ch-'0');
        }
        else if(ch=='(')
        {
            cs.push(ch);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' )
        {
            while (cs.size() > 0 && cs.top() != '(' && pre(ch) <= pre(cs.top()))
            {
            int v2=is.top();
            is.pop();
            int v1=is.top();
            is.pop();
            char op=cs.top();
            cs.pop();
            int ans=operation(v1,v2,op);
            is.push(ans);
        }
        cs.push(ch);
    }
    else if(ch==')')
    {
       while(cs.size()>0 && cs.top()!='(')
       {
           int v2=is.top();
            is.pop();
            int v1=is.top();
            is.pop();
            char op=cs.top();
            cs.pop();
            int ans=operation(v1,v2,op);
            is.push(ans);
       }
       if(cs.size()>0)
       {
           cs.pop();
       }
    }
}
while (cs.size() > 0) {
    int v2 = is.top();
    is.pop();
    int v1 = is.top();
    is.pop();
    char op = cs.top();
    cs.pop();

    int ans = operation(v1, v2, op);
    is.push(ans);
  }

  int ans = is.top();
  is.pop();
  cout << ans;
  return 0;
}
