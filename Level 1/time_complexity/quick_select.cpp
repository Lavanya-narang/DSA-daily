#include<iostream>
#include<vector>

using namespace std;


void swap(vector<int>& arr, int i, int j) {
  cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(vector<int>& arr, int pivot, int lo, int hi) {
  cout << "pivot -> " << pivot << endl;
  int curr = lo;
  int prev = lo - 1;
  while (curr <= hi) {
    if (arr[curr] <= pivot) {
      prev++;
      swap(arr, curr, prev);
    }
    curr++;
  }
  cout << "pivot index -> " << prev << endl;
  return prev;
}


int quickselect(vector<int>& arr, int low, int high, int k) {
  // write your code here
  int pivot=arr[high];
  int pivot_index=partition(arr,pivot,low,high);
  if(pivot_index<k)
  {
      return quickselect(arr,pivot_index+1,high,k);
  }
  else if(pivot_index>k)
  {
      return quickselect(arr,low,pivot_index-1,k);
  }
  else
  {
      return pivot;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;

  int ans = quickselect(arr, 0, n - 1, k - 1);
  cout << ans << endl;
  return 0;
}
