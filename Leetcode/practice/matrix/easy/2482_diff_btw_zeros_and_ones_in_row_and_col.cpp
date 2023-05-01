class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int row=grid.size(),col=grid[0].size();
        vector<vector<int>>ans(row,vector<int>(col,0));
        vector<int>zr(row,0),zc(col,0),oro(row,0),oc(col,0);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    oro[i]++;
                    oc[j]++;
                }
                else
                {
                    zr[i]++;
                    zc[j]++;
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                ans[i][j]=oro[i]+oc[j]-zr[i]-zc[j];
            }
        }
        return ans;
    }
};
