class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) 
    {
        int mx=0;
        int row=0;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=mat[i][j];
            }
            if(sum>mx)
            {
                mx=sum;
                row=i;
            }
        }
        return {row,mx};    
    }
};
