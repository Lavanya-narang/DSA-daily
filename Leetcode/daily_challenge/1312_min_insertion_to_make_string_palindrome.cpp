class Solution {
public:
int dp[1001][1001];
int solve(string &s,int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==s[j])
    {
        dp[i][j]=solve(s,i+1,j-1)+2;
    }
    else
    {
        dp[i][j]= max(solve(s,i+1,j),solve(s,i,j-1));
    }
    return dp[i][j];
}
int lps(string s)
{
    memset(dp,-1,sizeof(dp));
    return solve(s,0,s.size()-1);
}
    int minInsertions(string s) {
        return s.length()-lps(s);
    }
};
