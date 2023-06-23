// class Solution {
// public:
//     int longestArithSeqLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2)
//             return n;

//         int longest = 2;
//         vector<unordered_map<int, int>> dp(n);

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 int diff = nums[i] - nums[j];
//                 dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
//                 longest = max(longest, dp[i][diff]);
//             }
//         }

//         return longest;
//     }
// };


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        // vector<unordered_map<int,int>> vec(n);
        vector<vector<int>> dp(n, vector<int> (2000,0));
        int maxi = 0;
        for(int i =1;i<n;i++){
            for(int j= 0;j<i;j++){
                int diff = nums[j]-nums[i]+1000;
                dp[i][diff] = dp[j][diff]+1;
                maxi = max(maxi , dp[i][diff]);
            }
        }
        return maxi+1;
    }
};
