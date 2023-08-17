// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         if (mat.empty() || mat[0].empty())
//             return {};

//         int m = mat.size(), n = mat[0].size();
//         queue<pair<int, int>> queue;
//         int MAX_VALUE = m * n;
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (mat[i][j] == 0) {
//                     queue.push({i, j});
//                 } else {
//                     mat[i][j] = MAX_VALUE;
//                 }
//             }
//         }
        
//         vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
//         while (!queue.empty()) {
//             auto [row, col] = queue.front(); queue.pop();
//             for (auto [dr, dc] : directions) {
//                 int r = row + dr, c = col + dc;
//                 if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] > mat[row][col] + 1) {
//                     queue.push({r, c});
//                     mat[r][c] = mat[row][col] + 1;
//                 }
//             }
//         }
        
//         return mat;
//     }
// };


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size(), INF = m + n;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                int top = INF, left = INF;
                if (r - 1 >= 0) top = mat[r - 1][c];
                if (c - 1 >= 0) left = mat[r][c - 1];
                mat[r][c] = min(top, left) + 1;
            }
        }
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] == 0) continue;
                int bottom = INF, right = INF;
                if (r + 1 < m) bottom = mat[r + 1][c];
                if (c + 1 < n) right = mat[r][c + 1];
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};
