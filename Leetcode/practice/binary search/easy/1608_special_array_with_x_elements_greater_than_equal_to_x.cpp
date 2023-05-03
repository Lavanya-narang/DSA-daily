class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int low=1,high=nums.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2,count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>=mid)
                {
                    count++;
                }
            }
            if(count==mid)
            {
                return mid;
            }
            else if(count<mid)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
    }
};
