class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],cost[i]});
        }
        sort(begin(v),end(v));
        long long prefix[n];
        prefix[0]=0;
        long long totcost=v[0].second;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+abs(v[i].first-v[i-1].first)*totcost;
            totcost+=v[i].second;
        }
        long long suffix[n];
        totcost=v[n-1].second;
        suffix[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+abs(v[i].first-v[i+1].first)*totcost;
            totcost+=v[i].second;
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,prefix[i]+suffix[i]);
        }
        return ans;
    }
};
