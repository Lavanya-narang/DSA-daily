#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void transactions(vector<int> arr, int k) {
  //write your code here
   int n = arr.size();
  vector<vector<int>> dp(k + 1, vector<int>(n, 0));

  for (int t = 1; t <= k; t++)
  {
    int max = INT_MIN;
    for (int d = 1; d < arr.size(); d++)
    {
      if (dp[t - 1][d - 1] - arr[d - 1] > max)
      {
        max = dp[t - 1][d - 1] - arr[d - 1];
      }

      if (max + arr[d] > dp[t][d - 1])
      {
        dp[t][d] = max + arr[d];
      }
       else
      {
        dp[t][d] = dp[t][d - 1];
      }
    }
  }
  cout << dp[k][n - 1];
}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int k ;
  cin >> k;

  transactions(arr, k);

  return 0;
}
