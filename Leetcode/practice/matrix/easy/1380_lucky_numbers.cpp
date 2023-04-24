class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>ans;
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++)
        {
            int mn=matrix[i][0];
            for(int j=1;j<n;j++)
            {
                mn=min(mn,matrix[i][j]);
               
            }
            row[i]=mn;
        }
        for(int i=0;i<n;i++)
        {
            int mn=matrix[0][i];
            for(int j=1;j<m;j++)
            {
                mn=max(mn,matrix[j][i]);
                
            }
            col[i]=mn;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==col[j])
                {
                    ans.push_back(row[i]);
                }
            }
        }
        return ans;
    }
};
