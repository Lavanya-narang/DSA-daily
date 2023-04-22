class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                ans.push_back(i);
            }
        }
            
        return ans;
    }
};
