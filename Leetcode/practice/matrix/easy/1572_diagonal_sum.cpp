class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int ans=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
           ans=ans+mat[i][i]+mat[i][n-i-1];
        }
        if(n%2==0)
        {
            return ans;
        }
        else
        {
            return ans-mat[n/2][n/2];
        }
           
    }
};
