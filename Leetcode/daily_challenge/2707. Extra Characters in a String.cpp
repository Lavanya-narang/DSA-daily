// class Solution {
// public:
//     int solve(string& s, unordered_map<string, int>&mp, vector<int>&dp, int index)
//     {
//         if (index >= s.size()) return 0;
//         if (dp[index] != -1) return dp[index]; //use the stored results
        
//         string currStr = "";
//         int minExtra = s.size();
//         for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
//         {
//             currStr.push_back(s[cutIdx]);
//             //currStr will be a string from (index to cutIdx)
            
//             //if string not in dictionary, we have to delete as they are extra chars
//             int currExtra = (mp.count(currStr))? 0 : currStr.size();
//             int nextExtra = solve(s, mp, dp, cutIdx + 1);
//             int totalExtra = currExtra + nextExtra;
            
//             minExtra = min(minExtra, totalExtra);
//         }
//         return dp[index] = minExtra;
//     }
//     int minExtraChar(string s, vector<string>& dictionary) 
//     {
//         vector<int>dp(s.size(), -1);
//         unordered_map<string, int>mp;
//         for (string& word : dictionary) mp[word]++;
        
//         int ans = solve(s, mp, dp, 0);
//         return ans;
        
//     }
// };



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> memo(n, n+1);
        
        function<int(int)> dp;
        dp = [&](int j) -> int {
            if (j == n)
                return 0;
            if (memo[j] != n+1)
                return memo[j];
            
            memo[j] = n-j;
            for (auto &word: dictionary) {
                int startpos = s.find(word, j);
                if (startpos != string::npos) {
                    memo[j] = min(memo[j], startpos-j + dp(startpos + word.size()));
                }
            }

            return memo[j];
        };

        return dp(0);
    }
};
