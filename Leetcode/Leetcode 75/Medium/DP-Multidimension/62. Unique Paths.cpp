// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 1));
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return findPaths(m - 1, n - 1, dp);
    }
    int findPaths(int i, int j, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;
        if(dp.at(i).at(j) != -1) return dp.at(i).at(j);
        int left = findPaths(i, j - 1, dp);
        int up = findPaths(i - 1, j, dp);
        return dp.at(i).at(j) = left + up;
    }
};
