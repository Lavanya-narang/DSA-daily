class Solution {
public:
 int dp[201][201];
    int solve (vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return 4000001;
        }
        if (i == m-1 && j == n-1) {
            return grid[i][j];
        } 
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int right = grid[i][j] + solve(grid, i, j+1);
        int down = grid[i][j] + solve(grid, i+1, j);
        return dp[i][j] = min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0);
    }
};
