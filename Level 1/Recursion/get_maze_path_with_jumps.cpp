#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> get_maze_paths(int sr,int sc, int dr, int dc)
{
  if(sr==dr && sc==dc)
  {
      vector<string>bc;
      bc.push_back("");
      return bc;
  }
  if(sr>dr || sc>dc)
  {
    vector<string>bc;
    bc.push_back("");
    return bc;
  }
  vector<string> path;
  for(int i=1;i<=(dc-sc);i++)
  {
      vector<string> hp=get_maze_paths(sr,  sc+i,  dr,  dc);
      for(string s:hp)
      {
          path.push_back("h"+to_string(i)+s);
      }
  }
  for(int j=1;j<=(dr-sr);j++)
  {
      vector<string> vp=get_maze_paths(sr+j,  sc,  dr,  dc);
      for(string s:vp)
      {
          path.push_back("v"+to_string(j)+s);
      }
  }
  for(int k=1;k<=(dc-sc)&& k<=(dr-sr);k++)
  {
      vector<string> dp=get_maze_paths(sr+k,  sc+k,  dr,  dc);
      for(string s:dp)
      {
          path.push_back("d"+to_string(k)+s);
      }
  }
  return path;
  
}
void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}
