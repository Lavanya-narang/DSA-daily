#include<iostream>
#include<stack>
#include<string>
using namespace std;
void duplicatebrackets(string str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch==')')
        {
           if(st.top()=='(')
           {
                cout<<"true";
                return;
           }
           else
           {
               while(st.top()!='(')
               {
                   st.pop();
               }
               st.pop();
           }
        }
        else
        {
            st.push(ch);
        }
    }
    cout<<"false";
}
int main()
{
    string str;
    getline(cin,str);
    duplicatebrackets(str);
}
