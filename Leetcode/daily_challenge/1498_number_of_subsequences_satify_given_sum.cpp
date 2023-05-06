class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        int ans=0,mod=1e9+7;
         sort(nums.begin(),nums.end());
         vector<int>pow(nums.size(),1);
         for(int i=1;i<nums.size();i++)
         {
             pow[i]=pow[i-1]*2%mod;
         }
         int left=0,right=nums.size()-1;
            while(left<=right)
            {
                if(nums[left]+nums[right]>target)
                {
                    right--;
                }
                else
                {
                    ans+=pow[right-left];
                    ans%=mod;
                    left++;
                }
            }
        return ans;
    }
};
