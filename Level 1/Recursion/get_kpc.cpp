#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> codes = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"}; 
vector<string> getKPC(string s) 
{
  if(s.size()==0)
  {
      vector<string> bc;
      bc.push_back("");
      return bc;
  }
  char ch=s.at(0);
  string ros=s.substr(1,s.size()-1);
  vector<string> rres=getKPC(ros);
  vector<string>mres;
  int codeforch=ch-'0';
  for(int i=0;i<codes[codeforch].size();i++)
  {
      char chcode=codes[codeforch].at(i);
      for(int j=0;j<rres.size();j++)
      {
          string str=rres[j];
          string final=chcode+str;
          mres.push_back(final);
      }
  }
  return mres;
}
int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}
