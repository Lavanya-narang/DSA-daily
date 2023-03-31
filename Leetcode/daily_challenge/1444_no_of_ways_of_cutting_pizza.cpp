class Solution {
public:
    int ways(vector<string>& pizza, int k) 
    {
      int m=pizza.size(),n=pizza[0].size();
      vector<vector<vector<int>>>dp(k,vector<vector<int>>(m,vector<int>(n,-1))); 
      vector<vector<int>>presum(m+1,vector<int>(n+1,0));
      for(int r=m-1;r>=0;r--)
      {
          for(int c=n-1;c>=0;c--)
          {
              presum[r][c]=presum[r][c+1]+presum[r+1][c]-presum[r+1][c+1]+(pizza[r][c]=='A'?1:0);
          }
      } 
      return solve(m,n,k-1,0,0,dp,presum);
    }
    int solve(int m,int n,int k,int r,int c,vector<vector<vector<int>>>& dp,vector<vector<int>>& presum)
    {
        if(presum[r][c]==0)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }
        if(dp[k][r][c]!=-1)
        {
            return dp[k][r][c];
        }
        int ans=0;
        for(int nr=r+1;nr<m;nr++)
        {
            if(presum[r][c]-presum[nr][c]>0)
            {
                ans=(ans+solve(m,n,k-1,nr,c,dp,presum))%1000000007;
            }
        }
        for(int nc=c+1;nc<n;nc++)
        {
            if(presum[r][c]-presum[r][nc]>0)
            {
                ans=(ans+solve(m,n,k-1,r,nc,dp,presum))%1000000007;
            }
        }
        return dp[k][r][c]=ans;
    }
};
