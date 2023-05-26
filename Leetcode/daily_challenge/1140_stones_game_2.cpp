class Solution {
public:
int dp[101][201];
int help(int i,int m,vector<int>&p)
{
    if(i>=p.size())
    {
        return 0;
    }
    if(dp[i][m]!=-1)
    {
        return dp[i][m];
    }
    int ans=INT_MIN,total=0;
    for(int j=0;j<2*m;j++)
    {
        if(i+j<p.size())
        {
            total+=p[i+j];
            ans=max(ans,total-help(i+j+1,max(m,j+1),p));
        }
    }
    return dp[i][m]=ans;
}
    int stoneGameII(vector<int>& piles) 
    {
       int sum=0;
       for(auto a:piles)
       {
           sum+=a;
       }
       memset(dp,-1,sizeof(dp));
       int diff=help(0,1,piles); 
       return (sum+diff)/2;
    }
};
