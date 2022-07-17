#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> get_stair_paths(int n) 
{
  if(n==0)
  {
      vector<string> bc;
      bc.push_back("");
      return bc;
  }
  else if(n<0)
  {
    vector<string> bc;
    return bc;
  }
 
  vector<string>p;
  for(int i=1;i<=3;i++)
  {
    vector<string> path=get_stair_paths(n-i);
    for(int j=0;j<path.size();j++)
    {
        string ss=path[j];
        char noofsteps=(char)(i+'0');
        string ata=noofsteps+ss;
        p.push_back(ata);
    }  
  }
  return p;
}
int main() 
{
  int n;
  cin >> n;
  vector<string> ans = get_stair_paths(n);
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
