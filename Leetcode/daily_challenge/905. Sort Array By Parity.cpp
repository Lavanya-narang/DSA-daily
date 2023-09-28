class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j=nums.size()-1,i=0;
        while(i<j)
        {
            if(nums[i]%2==0)
            {
                i++;
            }
            else if(nums[j]%2!=0)
            {
                j--;
            }
            else if(nums[i]%2!=0 and nums[j]%2==0)
            {
                swap(nums[i++],nums[j--]);
            }
        }
        return nums;
    }
};
