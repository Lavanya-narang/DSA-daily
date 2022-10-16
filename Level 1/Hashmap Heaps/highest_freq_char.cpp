#include <bits/stdc++.h>
using namespace std;

int main()
{
string str;
cin >> str;

// write your code here
unordered_map<char,int>fmap;
for(int i=0;i<str.length();i++)
{
    fmap[str[i]]++;
}
int maxctr=0;
char ch;
for(pair<char,int> m:fmap)
{
    if(m.second>maxctr)
    {
        maxctr=m.second;
        ch=m.first;
    }
}
cout<<ch;
}
