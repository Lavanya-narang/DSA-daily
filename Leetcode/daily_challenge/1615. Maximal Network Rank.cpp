// class Solution {
// public:
//     int maximalNetworkRank(int n, vector<vector<int>>& roads) {
//         vector<int> degree(n, 0);
//         set<pair<int, int>> road_set;
        
//         for (auto& road : roads) {
//             degree[road[0]]++;
//             degree[road[1]]++;
//             road_set.insert({road[0], road[1]});
//             road_set.insert({road[1], road[0]});
//         }

//         int max_rank = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i+1; j < n; ++j) {
//                 int rank = degree[i] + degree[j];
//                 if (road_set.find({i, j}) != road_set.end()) {
//                     rank--;
//                 }
//                 max_rank = max(max_rank, rank);
//             }
//         }

//         return max_rank;
//     }
// };


class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>degree(n,0);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            degree[u]++;
            degree[v]++;
            graph[u][v]=1;
            graph[v][u]=1;
        }
        int ans=0;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph.size();j++){
                if(j!=i){
                    int rank=degree[i]+degree[j]-graph[i][j];
                    ans=max(ans,rank);
                }
            }
        }
        return ans;
    }
};
