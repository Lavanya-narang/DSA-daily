class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(vector<string>&words, string target, int colIdx, int targetIdx) {
        if (targetIdx == target.size()) {
            return 1;
        }
        if (colIdx == words[0].size()) {
            return 0;
        }
        int notPick = solve(words, target, colIdx+1, targetIdx)%MOD;
        int pick = 0, currWays = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i][colIdx] == target[targetIdx]) {
                currWays++;
            }
        }
        pick = (currWays%MOD * (long long)solve(words, target, colIdx+1, targetIdx+1)%MOD) % MOD;
        return (pick + notPick)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        return solve(words, target, 0, 0);
    }
};




class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(vector<string>&words, string target, vector<vector<int>>& dp, int colIdx, int targetIdx) {
        if (targetIdx == target.size()) {
            return 1;
        }
        if (colIdx == words[0].size()) {
            return 0;
        }
        if (dp[colIdx][targetIdx] != -1) {
            return dp[colIdx][targetIdx];
        }
        int notPick = solve(words, target, dp, colIdx+1, targetIdx)%MOD;
        int pick = 0, currWays = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i][colIdx] == target[targetIdx]) {
                currWays++;
            }
        }
        pick = (currWays%MOD * (long long)solve(words, target, dp, colIdx+1, targetIdx+1)%MOD) % MOD;
        return dp[colIdx][targetIdx] = (pick + notPick)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        vector<vector<int>>dp(n, vector<int>(target.size(), -1));
        return solve(words, target, dp, 0, 0);
    }
};

class Solution {
public:
    long long MOD = 1000000007;
    int solve(vector<vector<int>>&freq, string& target, vector<vector<int>>& dp, int colIdx, int targetIdx)
    {
        if (targetIdx == target.size()) {
            return 1; 
        }
        if (colIdx == freq[0].size()) {
            return 0;  
        }
        if (dp[colIdx][targetIdx] != -1) {
            return dp[colIdx][targetIdx];
        }
        
        int targetCh = target[targetIdx] - 'a';
        int notPick = solve(freq, target, dp, colIdx + 1, targetIdx);
        
        int pick = 0;
        if (freq[targetCh][colIdx] != 0)
        {
            int currWays = freq[targetCh][colIdx];
            int nextWays = solve(freq, target, dp, colIdx + 1, targetIdx + 1);
            pick = (currWays%MOD * nextWays%MOD) % MOD;
        }
        
        return dp[colIdx][targetIdx] = (pick % MOD + notPick % MOD) % MOD;
        
    }
    int numWays(vector<string>& words, string target) 
    {
        int m = words.size(), n = words[0].size();
        vector<vector<int>>freq(26, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[words[i][j] - 'a'][j]++; //freq of 'ch' in jth col
            }
        }
        vector<vector<int>>dp(n, vector<int>(target.size(), -1));
        int ans = solve(freq, target, dp, 0, 0);
        return ans;
    }
