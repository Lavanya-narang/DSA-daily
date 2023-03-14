class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        int i=0,count=0;
        unordered_map<int,int>mp;
        int currsum=0;
        while(i<n)
        {
            currsum+=nums[i];
            if(currsum==k)
            {
                count++;
            }
            if(mp.find(currsum-k)!=mp.end())
            {
                count+=mp[currsum-k];
            }
            mp[currsum]+=1;
            i++;
        }
        return count;
    }
};
