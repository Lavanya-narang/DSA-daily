#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cin >> arr[i];
  }
}
void targetSumPair(vector<int>& arr, int target)
{
  //write your code here
  sort(arr.begin(),arr.end());
  int low=0,high=arr.size()-1;
  while(low<high)
  {
    int sum=arr[low]+arr[high];
    if(sum==target)
    {
        cout<<arr[low]<<", "<<arr[high]<<endl;
        low++;
        high--;
    }
    else if(sum<target)
    {
        low++;
    }
    else
    {
        high--;
    }
  }
}
int main()
{
  int n, target;
  cin >> n;
  vector<int> vec(n, 0);
  input(vec);
  cin >> target;
  targetSumPair(vec, target);
  return 0;
}
