// class Solution {
// public:
// //top down dp
// int dp[50001];
// int helper(vector<int>& s,int i)
// {
//     if(i>=s.size())
//     {
//         return 0;
//     }
//     if(dp[i]!=-1)
//     {
//         return dp[i];
//     }
//     int ans=INT_MIN;
//     ans=max(ans,s[i]-helper(s,i+1));
//     if(i+1<s.size())
//     {
//         ans=max(ans,s[i]+s[i+1]-helper(s,i+2));
//     }
//     if(i+2<s.size())
//     {
//         ans=max(ans,s[i]+s[i+1]+s[i+2]-helper(s,i+3));
//     }
//     return dp[i]=ans;
// }
//     string stoneGameIII(vector<int>& stoneValue) 
//     {
//         memset(dp,-1,sizeof(dp));
//         int alice=helper(stoneValue,0);
//         if(alice>0)
//         {
//             return "Alice";
//         }
//         else if(alice==0)
//         {
//             return "Tie";
//         }
//         return "Bob";
//     }
// };




class Solution {
public:
//bottom up dp
    string stoneGameIII(vector<int>& s) 
    {
        int n=s.size();
        vector<int>dp(n+1,0);
        int i=n-1;
        while(i>=0)
        {
            int ans=INT_MIN;
    ans=max(ans,s[i]-dp[i+1]);
    if(i+1<s.size())
    {
        ans=max(ans,s[i]+s[i+1]-dp[s,i+2]);
    }
    if(i+2<s.size())
    {
        ans=max(ans,s[i]+s[i+1]+s[i+2]-dp[s,i+3]);
    }
    dp[i]=ans;
    i--;
        }
        int alice=dp[0];
        if(alice>0)
        {
            return "Alice";
        }
        else if(alice==0)
        {
            return "Tie";
        }
        return "Bob";
    }
};
