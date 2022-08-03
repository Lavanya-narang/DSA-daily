#include<iostream>
#include<string.h>
using namespace std;


void String_compression01(string str)
{
  //write your code here
  int i=0;
  while(i<str.length())
  {
      while(i<str.length() && str[i]==str[i+1])
      {
          i++;
      }
      cout<<str[i];
      i++;
  }
  cout<<endl;
}
void String_compression02(string str)
{
  //write your code here
  int i=0;
  while(i<str.length())
  {
      int count=1;
      while(i<str.length() && str[i]==str[i+1])
      {
          i++;
          count++;
      }
      cout<<str[i];
      if(count>1)
      {
          cout<< count;
      }
      i++;
  }
}

int main()
{
  string str;
  getline(cin, str);
  String_compression01(str);
  String_compression02(str);
}
