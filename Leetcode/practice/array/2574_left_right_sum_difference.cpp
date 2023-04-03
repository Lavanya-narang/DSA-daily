class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        //TC:O(n)    SC:O(1)
        int lsum=0,rsum=0,n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            rsum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            rsum-=nums[i];
            ans.push_back(abs(lsum-rsum));
            lsum=lsum+nums[i];
        }
        return ans;
    }
};
