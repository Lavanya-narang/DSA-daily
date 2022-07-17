#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  //write your code here
  int ns=arr.size();
  int rb[n];
  int lb[n];
  stack<int>str;
  stack<int>stl;
  rb[n-1]=-1;
  lb[0]=-1;
  str.push(arr[n-1]);
  stl.push(0);
  for(int i=ns-1;i>=0;i--)
  {
      while(str.size()>0 && arr[i]<=arr[str.top()])
      {
          str.pop();
      }
      if(str.size()==0)
      {
          rb[i]=n;
      }
      else
      {
          rb[i]=str.top();
      }
      str.push(i);
  }
  for(int i=1;i<ns;i++)
  {
      while(stl.size()>0 && arr[i]<=arr[stl.top()])
      {
          stl.pop();
      }
      if(stl.size()==0)
      {
          lb[i]=-1;
      }
      else
      {
          lb[i]=stl.top();
      }
      stl.push(i);
  }
   int marea=0;
  for(int i=0;i<ns;i++)
  {
      int w=rb[i]-lb[i]-1;
      int area=w*arr[i];
      if(area>marea)
      {
          marea=area;
          
      }
  }cout<< marea;
  return 0;
}
