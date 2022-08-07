#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

void Display(vector<int>& arr) {
  for (int ele : arr) {
    cout << ele << " ";
  }
}

void countsort(vector<int>& arr, int d) {
  // write your code here
  vector<int> farr(10,0);
  for(int i=0;i<arr.size();i++)
  {
      farr[arr[i]/d%10]++;
  }
  for(int i=1;i<farr.size();i++)
  {
      farr[i]+=farr[i-1];
  }
  vector<int> ans(arr.size(),0);
  for(int i=arr.size()-1;i>=0;i--)
  {
      int pos=farr[arr[i]/d%10]-1;
      ans[pos]=arr[i];
      farr[arr[i]/d%10]--;
  }
  for(int i=0;i<arr.size();i++)
  {
      arr[i]=ans[i];
  }
  cout << "After sorting on " << d << " place -> ";
  Display(arr);
  cout << endl;
}

void radixSort(vector<int>& arr) {
  // write your code here
    int max=arr[0];
    for(int val: arr)
    {
        if(val>max)
        {
            max=val;
        }
    }
    int exp=1;
    while(exp<=max)
    {
        countsort(arr,exp);
        exp*=10;
   }
}


int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  radixSort(arr);
  Display(arr);
  return 0;
}
