#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int> const& arr, int k) {

  //write your code here
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i=0;i<k;i++)
  {
      pq.push(arr[i]);
  }
  for(int i=k;i<arr.size();i++)
  {
      if(arr[i]>pq.top())
      {
          pq.pop();
          pq.push(arr[i]);
      }
  }
  return pq.top();

}

int main()
{
  vector<int>arr;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    int data;
    cin >> data;
    arr.push_back(data);
  }
  int k;
  cin >> k;
  for (int i = k; i > 0; i--)
    cout << findKthLargest(arr, i) << endl;

  return 0;

}
