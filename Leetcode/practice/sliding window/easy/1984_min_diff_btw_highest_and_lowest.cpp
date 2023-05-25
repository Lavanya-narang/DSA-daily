class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        int mn=INT_MAX;
        int i=0,j=k-1;
        sort(nums.begin(),nums.end());
        while(j<nums.size())
        {
            mn=min(mn,nums[j++]-nums[i++]);
        }
        return mn;
    }
};
