// class Solution {
// public: 
//     int rob(vector<int>& nums) {
//         int n = nums.size(), pre = 0, cur = 0;
//         for (int i = 0; i < n; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };


class Solution {
public:
    int func(int indx, vector<int>&nums,int n,vector<int>&dp)
    {
        if(indx == n-1)
          return nums[indx];
        
        if(dp[indx] != -1)
         return dp[indx];

        int l=nums[indx],r=0;
        if(indx+2 < n)
        l=l+func(indx+2,nums,n,dp);
        if(indx+1 < n)
        r=func(indx+1,nums,n,dp);

        dp[indx] = max(l,r);
        return dp[indx];
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
         vector<int>dp(n,-1);
         int ans = func(0,nums,n,dp);
         return ans;
    }
};
