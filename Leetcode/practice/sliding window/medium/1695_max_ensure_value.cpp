lass Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int sum=0,n=nums.size(),ans=0;
        unordered_set<int>s;
        int i=0,j=0;
        while(j<n)
        {
            while(s.count(nums[j])>0)
            {
                s.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            sum+=nums[j];
            s.insert(nums[j++]);
            ans=max(ans,sum);
        }
        return ans;
    }
};
