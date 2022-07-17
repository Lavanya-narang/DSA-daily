#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  // write your code here
  stack<int>st;
  
  int ns=arr.size();
  int nge[ns];
  st.push(ns-1);
  nge[ns-1]=ns;
  for(int i=ns-2;i>=0;i--)
  {
      while(st.size()>0 && arr[i]>=arr[st.top()])
      {
          st.pop();
      }
      if(st.size()==0)
      {
          nge[i]=ns;
      }
      else
      {
          nge[i]=st.top();
      }
      st.push(i);
  }
  
  int j=0;
  for(int i=0;i<=ns-k;i++)
  {
      if(j<i)
      {
          j=i;
      }
      while(nge[j]<i+k)
      {
          j=nge[j];
      }
      cout<<arr[j]<<endl;
  }
 

  return 0;
}
