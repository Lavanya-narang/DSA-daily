class Solution {
public:
bool dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j)
{
    int n=grid.size(),m=grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m)
    {
        return 0;
    }
    if(grid[i][j]==1 || vis[i][j])
    {
        return 1;
    }
    vis[i][j]=true;
    bool up=dfs(grid,vis,i-1,j);
    bool down=dfs(grid,vis,i+1,j);
    bool left=dfs(grid,vis,i,j-1);
    bool right=dfs(grid,vis,i,j+1);
    return up&down&left&right;
}
    int closedIsland(vector<vector<int>>& grid) 
    {
        //TC:O(m*n) SC:O(m*n)+recursive stack
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==0 && !vis[i][j])
                {
                    ans+=dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};
