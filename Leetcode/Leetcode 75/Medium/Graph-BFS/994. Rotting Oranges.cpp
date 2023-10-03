// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
        
//         int m = grid.size();
//         int n = grid[0].size();
        
//         int fresh = 0, time = -1;
        
//         vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//         queue<pair<int, int>> q;
        
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(grid[i][j] == 1) fresh++;
//                 else if(grid[i][j] == 2) q.push({i, j});
//             }
//         }
        
//         while(!q.empty()) {
//             int sz = q.size();
//             for(int i = 0; i < sz; i++) {
//                 auto cur = q.front();
//                 q.pop();
//                 for(auto dir: dirs) {
//                     int x = cur.first + dir.first;
//                     int y = cur.second + dir.second;
//                     if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1) {
//                         grid[x][y] = 2;
//                         q.push({x, y});
//                         fresh--;
//                     }
//                 }
//             }
//             time++;
//         }
        
//         return (fresh > 0) ? -1 : ((time == -1) ? 0 : time);
//     }
// };



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        // vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    // vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int temp = q.front().second;
            time = max(time,q.front().second);
            q.pop();

            if(row-1>=0 && grid[row-1][col] == 1){
                q.push({{row-1,col},time+1});
                grid[row-1][col] = 2;
            }
            if(col-1>=0 && grid[row][col-1] == 1){
                q.push({{row,col-1},time+1});
                grid[row][col-1] = 2;
            }
            if(row+1<n && grid[row+1][col] == 1){
                q.push({{row+1,col},time+1});
                grid[row+1][col] = 2;
            }
            if(col+1<m && grid[row][col+1] == 1){
                q.push({{row,col+1},time+1});
                grid[row][col+1] = 2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
