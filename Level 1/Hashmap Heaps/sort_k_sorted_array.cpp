#include <bits/stdc++.h>
using namespace std;

int sortK(int arr[], int n, int k) {

//write your code here
priority_queue<int,vector<int>,greater<int>>p;
for(int i=0;i<=k;i++)
{
    p.push(arr[i]);
}
for(int i=k+1;i<n;i++)
{
    cout<<p.top()<<endl;
    p.pop();
    p.push(arr[i]);
}
while(p.size()>0)
{
    cout<<p.top()<<endl;
    p.pop();
}
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    int data;
    cin >> data;
    arr[i] = data;
  }
  int k;
  cin >> k;
  sortK(arr, n, k);
  return 0;
}
