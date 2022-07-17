#include <bits/stdc++.h>
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
int main() {
  string str;
  getline(cin, str);

  // write your code here
    stack<char>operators;
    stack<string>prefix;
    stack<string>postfix;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(')
        {
            operators.push(ch);
        }
        else if((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z'))
        {
            string s=string(1,ch);
            prefix.push(s);
            postfix.push(s);
        }
        else if(ch=='+' || ch=='*' || ch=='/' || ch=='-')
        {
            while(operators.size()>0 && operators.top()!='(' && pre(ch)<=pre(operators.top()))
            {
                char op=operators.top();
                operators.pop();
                string s=string(1,op);
                string postv2=postfix.top();
                postfix.pop();
                string postv1=postfix.top();
                postfix.pop();
                postfix.push(postv1+postv2+op);
                
                string prev2=prefix.top();
                prefix.pop();
                string prev1=prefix.top();
                prefix.pop();
                prefix.push(s+prev1+prev2);
            }
            operators.push(ch);
        }
        else if(ch==')')
        {
            while(operators.size()>0 && operators.top()!='(')
            {
                char op=operators.top();
                operators.pop();
                string s=string(1,op);
                string postv2=postfix.top();
                postfix.pop();
                string postv1=postfix.top();
                postfix.pop();
                postfix.push(postv1+postv2+op);
                
                string prev2=prefix.top();
                prefix.pop();
                string prev1=prefix.top();
                prefix.pop();
                prefix.push(s+prev1+prev2);
            }
            operators.pop();
        }
    }
    while(operators.size()>0)
    {
        char op=operators.top();
                operators.pop();
                string s=string(1,op);
                string postv2=postfix.top();
                postfix.pop();
                string postv1=postfix.top();
                postfix.pop();
                postfix.push(postv1+postv2+op);
                
                string prev2=prefix.top();
                prefix.pop();
                string prev1=prefix.top();
                prefix.pop();
                prefix.push(s+prev1+prev2);
        
    }
    string post=postfix.top();
    string pre=prefix.top();
    cout<<post<<endl;
    cout<<pre<<endl;
  return 0;
}
