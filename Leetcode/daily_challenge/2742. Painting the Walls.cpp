
// class Solution {
// private:
//     int memo(vector<int>&cost, vector<int> &time, int index, int walls, vector<vector<int>> &dp) {
//         if(walls <= 0) return 0;//can be one of the possible way
//         if(index < 0 ) return 1e9;//Neglect this by returning unusually large value
//         if(dp[index][walls] != -1) return dp[index][walls];

//         int notTake = 0 + memo(cost, time, index - 1, walls, dp);
//         int take = cost[index] + memo(cost, time, index - 1, walls- time[index] - 1, dp);
//         return dp[index][walls] = min(notTake, take);
//     }
// public:
//     int paintWalls(vector<int>& cost, vector<int>& time) {
//         int n = cost.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//         return memo(cost, time, n-1, n, dp);

        
//     }
// };



class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int c = cost[i];
            int t = time[i] + 1;
            for (int j = n; j >= 0; j--) {
                f[j] = min(f[j], f[max(j - t, 0)] + c);
            }
        }
        return f[n];
    }
};
