// class Solution {
//     struct State {
//      int mask, node, dist;
//     };
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n = graph.size();
//         int all_visited = (1 << n) - 1;
//         queue<State> q;
//         unordered_set<int> visited;
        
//         for (int i = 0; i < n; ++i) {
//             q.push({1 << i, i, 0});
//             visited.insert((1 << i) * 16 + i);
//         }
        
//         while (!q.empty()) {
//             State cur = q.front(); q.pop();
            
//             if (cur.mask == all_visited) {
//                 return cur.dist;
//             }
            
//             for (int neighbor : graph[cur.node]) {
//                 int new_mask = cur.mask | (1 << neighbor);
//                 int hash_value = new_mask * 16 + neighbor;
                
//                 if (visited.find(hash_value) == visited.end()) {
//                     visited.insert(hash_value);
//                     q.push({new_mask, neighbor, cur.dist + 1});
//                 }
//             }
//         }
        
//         return -1;
//     }
// };


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size() ;
        if(n==1) return 0 ;

        int finalMask = (1<<n) -1 ;
        vector<vector<bool>> visited(n, vector<bool>(finalMask, false)) ;

        queue<pair<int, int>> q ; 
        for(int i=0 ; i<n ; i++){
            q.push({i,1<<i}) ;
        }

        int shortestPath = 0 ;
        while(!q.empty()){
            shortestPath++;
            int l = q.size() ;
            while(l--){
                auto it = q.front() ; 
                q.pop() ;
                int currState = it.first ;
                int currMask = it.second ;

                for(auto &adjNode: graph[currState]){
                    int nextMask = currMask | 1<< adjNode;
                    if(nextMask == finalMask) return shortestPath;
                    if(!visited[adjNode][nextMask]){
                        visited[adjNode][nextMask] = true;
                        q.push({adjNode, nextMask});
                    }
                }
            }
        }

        return -1;
    }
};
