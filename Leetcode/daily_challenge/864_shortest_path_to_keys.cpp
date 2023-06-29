// class Solution {
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         unordered_map<char, int> key_bit;
//         int bit_start = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (islower(grid[i][j]))
//                     key_bit[grid[i][j]] = bit_start++;
        
//         int mask_end = (1 << bit_start) - 1;
//         int mask_size = (1 << bit_start);

       
//         vector<vector<vector<bool>>> memo(m,vector<vector<bool>>(n,  vector<bool>(mask_size,false)));

       
//         vector<int> start;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (grid[i][j] == '@')
//                     start = {i,j,0}; // 0 denoting no key state

//         queue<vector<int>> q;
//         q.push(start);
//         int step = 0;
//         while (!q.empty())
//         {
//             int size = q.size();
//             for (int k = 0; k < size; k++)
//             {
//                 int row = q.front()[0];
//                 int col = q.front()[1];
//                 int mask = q.front()[2];
//                 q.pop();

               
//                 if (row < 0 || row >= m || col < 0 || col >= n)
//                     continue;

            
//                 if (grid[row][col] == '#') continue;

            
//                 if (isupper(grid[row][col]))
//                     if ((mask & (1 << key_bit[tolower(grid[row][col])])) == 0)
//                         continue;

               
//                 if (islower(grid[row][col]))
//                     mask = mask | (1 << key_bit[grid[row][col]]);

               
//                 if (mask == mask_end) return step;

                
//                 if (memo[row][col][mask]) continue;
//                 memo[row][col][mask] = true;

               
//                 q.push({row+1, col, mask});
//                 q.push({row-1, col, mask});
//                 q.push({row, col+1, mask});
//                 q.push({row, col-1, mask});
//             }
//             step++;
//         }
//         return -1;
//     }
// };
class Solution {
    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,1,-1};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n, vector<int>(m));
        vector<int> lock(7,0);
        int sx, sy;
        int lk = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '@')
                {
                    sx = i, sy = j;
                    matrix[i][j] = 0;
                }
                else if(grid[i][j] == '.')
                {
                    matrix[i][j] = 0;
                    
                }
                else if(grid[i][j] >= 'A' && grid[i][j] <= 'F')
                {
                    matrix[i][j] = -1*((grid[i][j]-'A') + 1);
                    lock[(grid[i][j]-'A') + 1] = (1 << (grid[i][j]-'A'));
                }
                else if(grid[i][j] == '#')
                    matrix[i][j] = -8;
                else
                {
                    matrix[i][j] = (1 << (grid[i][j]-'a'));
                    lk++;
                }
                
            }
            
        }
        int fnl =  (1 << lk) - 1;
        
        vector<vector<int>> visited(n*m, vector<int>(fnl,1));
        queue<pair<pair<int,int>,int>> q;
        int ans = 0;
        q.push({{sx,sy},0});
        visited[sx*m+sy][0] = 0;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            while(sz--)
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int bit = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nxtx = x + dirx[i];
                    int nxty = y + diry[i];
                    if(nxtx >= n || nxtx < 0 || nxty >= m || nxty < 0) continue;
                    if(matrix[nxtx][nxty] == -8) continue;
                    if(visited[nxtx*m+nxty][bit] == 0) continue;
                    if(matrix[nxtx][nxty] < 0)
                    {
                        int lkidx = -1*matrix[nxtx][nxty];
                        if(bit&lock[lkidx])
                        {
                            q.push({{nxtx,nxty},bit});
                            visited[nxtx*m+nxty][bit] = 0;
                        }
                    }
                    else if(matrix[nxtx][nxty] == 0)
                    {
                        q.push({{nxtx,nxty},bit});
                        visited[nxtx*m+nxty][bit] = 0;
                        continue;
                    }
                    else
                    {
                        int fbit = bit | matrix[nxtx][nxty];
                        if(fbit == fnl) return ans;
                        q.push({{nxtx,nxty},fbit});
                        visited[nxtx*m+nxty][fbit] = 0;
                    }
                }
            }
        }
        return -1;
    }
};
