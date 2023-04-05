class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        //TC:O(m*n) SC:O(1)
        int n=accounts[0].size(),m=accounts.size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=accounts[i][j];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
