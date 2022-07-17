#include <iostream>
using namespace std;
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
void printKPC(string ques, string asf)
{
    if(ques.length()==0)
    {
        cout<<asf<<endl;
        return;
    }
    char ch=ques[0];
    string roq=ques.substr(1);
    for(char chcode: codes[ch-'0'])
    {
        printKPC(roq,asf+chcode);
    }
}
int main()
{
    string str;
    cin >> str;
    printKPC(str, "");
}
