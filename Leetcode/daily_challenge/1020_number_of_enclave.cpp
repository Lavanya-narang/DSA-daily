class Solution {
public:
bool dfs(vector<vector<int>>& grid,int i,int j,int &cnt,vector<vector<bool>>&vis)
{
    //TC:O(m*n) SC:O(m*n)
     int r=grid.size(),c=grid[0].size();
     if(i<0 || j<0 || i>=r || j>=c)
     {
         return 0;
     }
     if(grid[i][j]==0 || vis[i][j])
     {
         return 1;
     }
     vis[i][j]=true;
     cnt+=1;
     bool up=dfs(grid,i-1,j,cnt,vis);
     bool down=dfs(grid,i+1,j,cnt,vis);
     bool left=dfs(grid,i,j-1,cnt,vis);
     bool right=dfs(grid,i,j+1,cnt,vis);
     return up&down&left&right;
}
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        int ans=0;
        for(int i=1;i<r-1;i++)
        {
            for(int j=1;j<c-1;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    int cnt=0;
                    if(dfs(grid,i,j,cnt,vis))
                    {
                        ans+=cnt;
                    }
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//TC:O(m*n) SC:O(m*n)
//     void bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         visit[x][y] = 2;

//         vector<int> dirx{0, 1, 0, -1};
//         vector<int> diry{-1, 0, 1, 0};

//         while (!q.empty()) {
//             x = q.front().first;   // row nnumber
//             y = q.front().second;  // column number
//             q.pop();

//             for (int i = 0; i < 4; i++) {
//                 int r = x + dirx[i];
//                 int c = y + diry[i];
//                 if (r < 0 || r >= m || c < 0 || c >= n) {
//                     continue;
//                 } else if (grid[r][c] == 1 && !visit[r][c]) {
//                     q.push({r, c});
//                     visit[r][c] = true;
//                 }
//             }
//         }
//         return;
//     }

//     int numEnclaves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<bool>> visit(m, vector<bool>(n));

//         for (int i = 0; i < m; ++i) {
//             // First column.
//             if (grid[i][0] == 1 && !visit[i][0]) {
//                 bfs(i, 0, m, n, grid, visit);
//             }
//             // Last column.
//             if (grid[i][n - 1] == 1 && !visit[i][n - 1]) {
//                 bfs(i, n - 1, m, n, grid, visit);
//             }
//         }

//         for (int i = 0; i < n; ++i) {
//             // First row.
//             if (grid[0][i] == 1 && !visit[0][i]) {
//                 bfs(0, i, m, n, grid, visit);
//             }
//             // Last row.
//             if (grid[m - 1][i] == 1 && !visit[m - 1][i]) {
//                 bfs(m - 1, i, m, n, grid, visit);
//             }
//         }

//         int count = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1 && !visit[i][j]) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
