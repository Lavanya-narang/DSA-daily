class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
       for(int i=0;i<n;i++)
       {
           sort(grid[i].begin(),grid[i].end());
       }
       for(int i=0;i<m;i++)
       {
           int mn=INT_MIN;
           for(int j=0;j<n;j++)
           {
               mn=max(mn,grid[j][i]);
           }
           ans+=mn;
       }
        return ans;

    }
};
