class Solution {
public:
    double new21Game(int n, int k, int maxPts) 
    {
        //TC:O(N) SC:O(N)
        if(k==0 || n>=k+maxPts)
        {
            return 1;
        }
        vector<double>dp(n+1,0.0);
        dp[0]=1;
        double currsum=dp[0];
        for(int i=1;i<=n;i++)
        {
            dp[i]=currsum/(double)maxPts;
            if(i<k)
            {
                currsum+=dp[i];
            }
            if(i-maxPts>=0)
            {
                currsum-=dp[i-maxPts];
            }
        }
        double ans=0.0;
        for(int i=k;i<=n;i++)
        {
            ans+=dp[i];
        }
        return ans;
    }
};
