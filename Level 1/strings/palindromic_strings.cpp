#include<iostream>
#include<string.h>
using namespace std;
bool ispalindrome(string str)
{
    int low=0;
    int high=str.length()-1;
    while(low<=high)
    {
        if(str[low]!=str[high])
        {
            return false;
        }
        else
        {
         low++;
        high--;
        }
    }
    return true;
}
void printallpalindrome(string str)
{
  //write your code here
  for(int i=0;i<str.length();i++)
  {
      for(int j=1;i+j<=str.length();j++)
      {
          string s=str.substr(i,j);
          if(ispalindrome(s)==true)
          {
              cout<<s<<endl;
          }
      }
  }
}

int main()
{
  string str;
  getline(cin, str);
  printallpalindrome(str);
  return 0;
}
