class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        //tc:o(n)
        //sc:o(n)
        // int n=nums.size();
        // vector<int>ans(n,0);
        
        // for(int i=0;i<n;i++)
        // {
        //     int temp=nums[i];
        //     ans[i]=nums[temp];
        // }    
        // return ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]+n*(nums[nums[i]]%n);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]/=n;
        }
        return nums;
    }
};
