class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,curr=0,farthest=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            farthest=max(farthest,nums[i]+i);
            if(i==curr)
            {
                curr=farthest;
                jumps++;
            }
        }
        return jumps;
    }
};