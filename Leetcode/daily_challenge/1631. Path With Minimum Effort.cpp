// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         int rows = heights.size(), cols = heights[0].size();
//         vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
//         minHeap.emplace(0, 0, 0);
//         dist[0][0] = 0;
        
//         int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
//         while (!minHeap.empty()) {
//             auto [effort, x, y] = minHeap.top();
//             minHeap.pop();
            
//             if (effort > dist[x][y]) continue;
            
//             if (x == rows - 1 && y == cols - 1) return effort;
            
//             for (auto& dir : directions) {
//                 int nx = x + dir[0], ny = y + dir[1];
//                 if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
//                     int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
//                     if (new_effort < dist[nx][ny]) {
//                         dist[nx][ny] = new_effort;
//                         minHeap.emplace(new_effort, nx, ny);
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        priority_queue<pair<int, pair<int, int>>> q;
        q.push({0,{0, 0}});
        dist[0][0] = 0;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while(!q.empty())
        {
            int curr = -q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            if(x == n-1 && y == m-1) return curr;
            
            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m)
                {
                    int diff = max(abs(heights[newX][newY] - heights[x][y]), curr);
                    if(dist[newX][newY] > diff)
                    {
                        dist[newX][newY] = diff;
                        q.push({-diff,{newX,newY}});
                    }
                }
            }


        }
        return 0;
    }
};
