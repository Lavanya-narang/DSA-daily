// class Solution {
// public:
// int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&memo)
// {
//     if(i>=nums1.size() || j>=nums2.size())
//     {
//         return 0;
//     }
//     if(memo[i][j]!=-1)
//     {
//         return memo[i][j];
//     }
//     if(nums1[i]==nums2[j])
//     {
//         memo[i][j]=1+solve(i+1,j+1,nums1,nums2,memo);
//     }
//     else
//     {
//         memo[i][j]=max(solve(i+1,j,nums1,nums2,memo),solve(i,j+1,nums1,nums2,memo));
//     }
//     return memo[i][j];
// }
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
//     {
//         int n=nums1.size();
//         int n2=nums2.size();
//         vector<vector<int>>memo(n+1,vector<int>(n2+1,-1));
//         return solve(0,0,nums1,nums2,memo);
//     }
// };



class Solution {
public:

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>memo(n1+1,vector<int>(n2+1));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                // if(nums1[i-1]==nums2[j-1])
                // {
                //     memo[i][j]=1+memo[i-1][j-1];
                // }
                // else
                // {
                //     memo[i][j]=max(memo[i][j-1],memo[i-1][j]);
                // }
                memo[i][j]=nums1[i-1]==nums2[j-1]?(1+memo[i-1][j-1]):max(memo[i-1][j],memo[i][j-1]);
            }
        }
        return memo[n1][n2];
    }
};
