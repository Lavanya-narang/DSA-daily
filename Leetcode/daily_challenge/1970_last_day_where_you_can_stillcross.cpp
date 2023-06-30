// class Solution {
// public:
//     int X[4]= {0,0,-1,1};
//     int Y[4] = {-1,1,0,0};
//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
//         int n = row;
//         int m = col;
//         vector<vector<int>> a(n,vector<int>(m,0));
//         int x = 0;
//         int lday = 0;
//         int rday = cells.size()-1;
//         while(lday<=rday)
//         {
//             int mid = (lday+rday)/2;
//             for(int j=0;j<mid;j++)
//             {
//                 a[cells[j][0]-1][cells[j][1]-1]=1;
//             }
//             if(bfs(a,n,m))
//             {
//                 lday = mid+1;
//                 x = mid;
//             }
//             else
//             {
//                 rday = mid-1;
//             }
//             for(int j=0;j<mid;j++)
//             {
//                  a[cells[j][0]-1][cells[j][1]-1]=0;
//             }
//         }
//         return x;
//     }    
//     bool bfs( vector<vector<int>> a , int n , int m)
//     {
//         queue<pair<int,int>>q;
//         for(int i=0;i<m;i++)
//         {
//                 if(a[0][i]==0)
//                 {
//                     q.push({0,i});
//                     a[0][i] = 1;
//                 }
//         }
        
//         while(!q.empty())
//         {
//             int ss = q.size();
//             while(ss--)
//             {
//                 pair<int,int>pr = q.front();q.pop();
//                 int ii = pr.first;
//                 int jj = pr.second;
// 				// if we get last row means we are able to reach return true
//                 if(ii==n-1)
//                     return true;
//                 for(int i=0;i<4;i++)
//                 {
//                     int nx = ii + X[i];
//                     int ny = jj + Y[i];
//                     if(nx>=0 and nx<n and ny>=0 and ny<m and a[nx][ny]==0)
//                     {
//                         q.push({nx,ny});
//                         a[nx][ny]=1;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        initialize(row, col);
        auto isLand = vector(row, vector(col, false));
        const vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = cells.size()-1; i>=0; i--){
            int x = cells[i][0]-1, y = cells[i][1]-1;
            isLand[x][y] = true;
            for(auto [dx, dy]:dirs){
                int i = x+dx, j=y+dy;
                if(i<0 || i>=row || j<0 ||j>=col || !isLand[i][j]) continue;
                join(key(x,y), key(i, j));
            }
            if(connect()) return i;
        }
        return -1;
    }

    void join(int i, int j){
        vroot[root(i)] = root(j);
    }

    int root(int i){
        if(vroot[i] == i) return i;
        return vroot[i] = root(vroot[i]);
    }

    bool connect() {
        return root(top) == root(bottom);
    }

    int key(int x, int y){
        return x*col+y;
    }

    void initialize(int row, int col){
        this->row = row;
        this->col = col;
        top = row * col;
        bottom = top+1;
        vroot.resize(row*col+2);
        for(int i=0;i<vroot.size();i++) vroot[i] = i;
        for(int j=0;j<col;j++) {
            join(key(0, j), top);
            join(key(row-1, j), bottom);
        }
    }

    int row;
    int col;
    int top;
    int bottom;
    vector<int> vroot;
};
