class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int i=0,j=0,n=nums.size();
        int mx=INT_MIN;
        int ans=0;
        while(j<nums.size())
        {
            ans+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mx=max(mx,ans);
                ans-=nums[i];
                i++;j++;
            }
        }
        return mx/(double)k;
    }
};
