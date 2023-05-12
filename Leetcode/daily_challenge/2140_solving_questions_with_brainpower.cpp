class Solution {
public:
    long long solve(vector<vector<int>>& questions,int i,int n,vector<long long>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
             return dp[i];
        }
        long long way1=questions[i][0]+solve(questions,i+questions[i][1]+1,n,dp);
        long long way2=solve(questions,i+1,n,dp);
        return dp[i]=max(way1,way2);
    }
    long long mostPoints(vector<vector<int>>& questions) 
    {
        
        int n=questions.size();
        vector<long long>dp(n,-1);
        return solve(questions,0,n,dp);
    }
};
