#include <bits/stdc++.h>

using namespace std;


int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {

  //write your code here
    for(int j=m-1;j>=0;j--)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(j==m-1) //last col
            {
                dp[i][j]=arr[i][j];
            }
            else if(i==0)//1st row
            {
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1)//last row
            {
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);
            }
            else
            {
                dp[i][j]=arr[i][j]+max(max(dp[i-1][j+1],dp[i+1][j+1]),dp[i][j+1]);
            }
        }
    }
    int maxgold=dp[0][0];
    for(int i=0;i<dp.size();i++)
    {
    maxgold=max(maxgold,dp[i][0]);
    }
  return (maxgold);
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int>(m, 0));

  cout << collectGold(n, m, arr, dp);

}
