class Solution {
public:
 int dp[101][101][101];
    int MOD = 1e9+7;
    int solve(int membersSelected, int currProfit, int index, int n, int minProfit, vector<int>&group, vector<int>&profit) {
        if (index >= group.size()) {
            return currProfit >= minProfit;
        }

        if (dp[index][membersSelected][currProfit] != -1) {
            return dp[index][membersSelected][currProfit];
        }

        int notSelect = solve(membersSelected, currProfit, index+1, n, minProfit, group, profit);
        int select = 0;

        if (membersSelected + group[index] <= n) {
            select += solve(membersSelected + group[index], min(minProfit, currProfit + profit[index]), index+1, n, minProfit, group, profit);
        }

        return dp[index][membersSelected][currProfit] = (notSelect%MOD + select%MOD)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, minProfit, group, profit);  
    }
};
