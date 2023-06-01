// class Solution 
// {
//     int xx[8]={0,0,-1,1,-1,-1,1,1};
//     int yy[8]={1,-1,0,0,-1,1,1,-1};
// int solve(vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m,int x,int y,int cnt)
// {
//     if(x==n-1 and y==n-1)
//     {
//         return cnt;
//     }
//     int mcnt=INT_MAX;
//     vis[x][y]=1;
//     for(int i=0;i<8;i++)
//     {
//         int nx=x+xx[i],ny=y+yy[i];
//         if(nx<n and nx>=0 and ny<n and ny>=0 and !grid[nx][ny] and !vis[nx][ny])
//         {
//             mcnt=min(mcnt,solve(grid,vis,n,m,nx,ny,cnt+1));
//         }
        
//     }
//     vis[x][y]=0;
//     return mcnt;
// }
 
// public:
//    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
//     {
//         if(grid[0][0]==1)
//         {
//             return -1;
//         }
//         int n=grid.size(),m=grid[0].size();
//         if(n==1)
//         {
//             return 1;
//         }
//         int i=0,j=0;
        
//         vector<vector<int>>vis(n,vector<int>(n,0));
//         int ans=solve(grid,vis,n,m,0,0,1);
//         return ans!=INT_MAX? ans:-1;
//     }
// };



class Solution 
{
public:
   int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
       int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        std::queue<std::vector<int>> queue;
        queue.push({0, 0, 1});
        grid[0][0] = 1;

        std::vector<std::vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            int row = current[0];
            int col = current[1];
            int distance = current[2];

            if (row == n - 1 && col == n - 1) {
                return distance;
            }

            for (const auto& direction : directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0) {
                    grid[newRow][newCol] = 1;
                    queue.push({newRow, newCol, distance + 1});
                }
            }
        }

        return -1;
    }
};
