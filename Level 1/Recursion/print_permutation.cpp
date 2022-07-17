#include <iostream>
using namespace std;
void printPermutations(string str, string asf)
{
    if(str.length()==0)
    {
        cout<<asf<<endl;
        return;
    }
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        string leftch=str.substr(0,i);
        string rightch=str.substr(i+1);
        string ros=leftch+rightch;
    printPermutations(ros,asf+ch);
}
}
int main()
{
    string str;
    cin>>str;
    printPermutations(str,"");
    
}
