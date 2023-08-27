// class Solution {
// public:
//     bool canCross(vector<int>& stones) {
//         int N = stones.size();
//         vector<vector<bool>> dp(N, vector<bool> (N+1, false));
//         dp[0][1] = true;
        
//         for(int i = 1; i < N; ++i){
//             for(int j = 0; j < i; ++j){
//                 int diff = stones[i] - stones[j];
//                 if(diff > N || !dp[j][diff]) 
//                     continue;
                
//                 if(i == N - 1) 
//                     return true;
                
//                 dp[i][diff] = true;
//                 if(diff - 1 >= 0) dp[i][diff - 1] = true;
//                 if(diff + 1 <= N) dp[i][diff + 1] = true;
//             }
//         }

//         return false;
//     }
// };


class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool bCheck = false;
        return canCross(stones, 0, 0, stones.size(), bCheck);
    }

    bool canCross(vector<int>& stones, int i, int k, int n, bool& bCheck){
        if (i == n-1)
            return true;
        if (stones[i+1] > stones[i] + k + 2){
            bCheck = true;
            return false;
        }
        static vector<int> dirs = {1,0,-1};
        for (int dir : dirs){
            int next = dir + k;
            if (binary_search(stones.begin(), stones.end(), stones[i] + next)){
                int j = i + 1;
                while (j < n && stones[j] != stones[i] + next){
                    if (stones[j] > stones[i] + next)
                        break;
                    j++;
                }
                if (j < n && stones[j] == stones[i] + next){
                    if (canCross(stones, j, next, n, bCheck))
                        return true;
                    if (bCheck)
                        return false;
                }
            }
        }
        return false;
    }
};
