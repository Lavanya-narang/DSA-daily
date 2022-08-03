#include<iostream>
#include<string.h>

using namespace std;

void printstr(string str)
{
  //write your code here
  int i=0;
  for(i=0;i<str.length()-1;i++)
  {
      int diff=(int)str[i+1]- (int)str[i];
      cout<<str[i]<<diff;
     
  }
 cout<<str[i];
}
int main()
{
  string str;
  getline(cin, str);
  printstr(str);
  return 0;
}
