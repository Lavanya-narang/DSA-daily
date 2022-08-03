#include<iostream>
#include<string>
using namespace std;

void togglecase(string str)
{
  //write your code here
  for(int i=0;i<str.length();i++)
  {
      if(str[i]>='a' && str[i]<='z')
      {
          str[i]=(char)('A'+str[i]-'a');
      }
      else
      {
          str[i]=(char)('a'-'A'+str[i]);
      }
  }
  cout<<str;
}

int main() {
  string str;
  getline(cin, str);
  togglecase(str);
  return 0;
}
