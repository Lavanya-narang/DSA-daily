class Solution {
public:
int calculate(vector<int> &nums,int goal)
{
    int i=0,j=0,n=nums.size(),s=0,cnt=0;
        if(goal<0)
        {
            return 0;
        }
        while(j<n)
        {
            s+=nums[j];
            if(s>goal)
            {
                while(s>goal and i<n)
                {
                    s-=nums[i];
                    i++;
                }
            }
             cnt+=j-i+1;
            j++;
        }
       return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return calculate(nums,goal)-calculate(nums,goal-1);
    }
};
