class Solution {
public:
int MOD=1e9+7;
int solve(string &s,int k,int ind,vector<int>&dp)
{
    if(ind>=s.size())
    {
        return 1;
    }
    if(s[ind]=='0')
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int ways=0;
    long currnum=0;
    for(int i=ind;i<s.length();i++)
    {
        currnum=currnum*10+s[i]-'0';
        if(currnum>k)
        {
            break;
        }
        ways=(ways+solve(s,k,i+1,dp))%MOD;
    }
    return dp[ind]=ways;
}
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.size(),-1);
        return solve(s,k,0,dp);
    }
};
