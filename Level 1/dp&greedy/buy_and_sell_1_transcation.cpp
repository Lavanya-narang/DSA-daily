#include <iostream>
#include <vector>

using namespace std;

void Transaction(vector<int> arr) {
  //write your code here
  int msf=arr[0];
  int op=0;
  for(int i=1;i<arr.size();i++)
  {
      if(arr[i]<msf)
      {
          msf=arr[i];
      }
      int cp=arr[i]-msf;
      if(cp>op)
      {
          op=cp;
      }
  }
  cout<<op<<endl;
}

int  main() {
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  Transaction(arr);
  return 0;
}
