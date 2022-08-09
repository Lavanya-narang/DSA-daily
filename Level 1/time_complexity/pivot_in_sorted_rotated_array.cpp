#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cin >> arr[i];
  }
}
int findpivot(vector<int>& arr)
{
  //write your code here
  int low=0;
  int high=arr.size()-1;
  while(low<high)
  {
      int mid=(low+high)/2;
      if(arr[mid]<arr[high])
      {
          high=mid;
      }
      else if(arr[mid]>arr[high])
      {
          low=mid+1;
      }
  }
    return arr[high];
  
}
int main()
{
  int n;
  cin >> n;
  vector<int> vec(n, 0);
  input(vec);
  int pivot = findpivot(vec);
  cout << pivot;
  return 0;
}
