class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) 
    {//TC:O(n) SC:O(1)
        long sum=0,res=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};
