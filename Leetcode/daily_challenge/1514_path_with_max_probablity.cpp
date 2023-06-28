// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

//         // Adjacency list
//         vector<vector<pair<int, double>>> adj(n);
//         for (int i = 0; i < edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             adj[u].push_back({v, succProb[i]});
//             adj[v].push_back({u, succProb[i]});
//         }

//         // ans will be in dist[end]
//         vector<double> dist(n, 0.0);
//         dist[start] = 1.0;
        
//         queue<int> q;
//         q.push(start);
        
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
            
//             for (auto x : adj[curr]) {
//                 int node = x.first;
//                 double prob = x.second;
//                 double newProb = dist[curr] * prob;
                
//                 if (newProb > dist[node]) {
//                     dist[node] = newProb;
//                     q.push(node);
//                 }
//             }
//         }
        
//         return dist[end];
//     }
// };


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector <pair<double,double>> adj[n+1];
        vector <double> prob(n,0);
        queue <int> q;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        q.push(start);
        prob[start]=1;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node]){
                double p=it.second;
                int adjNode=it.first;
                
                if(prob[node]*p > prob[adjNode]){
                    prob[adjNode]=prob[node]*p;
                    q.push(adjNode);
                }
            }
        }
        if(prob[end]==0) return 0;
        else return prob[end];
    }
};
