// class Solution {
// public:
// bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> graph(numCourses);
//         vector<int> degree(numCourses, 0);
//         queue<int> zeroDegree;
//         for(int i = 0; i<prerequisites.size(); i++){
//             graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             degree[prerequisites[i][0]]++;
//         }
        
//         for(int i = 0; i<degree.size(); i++){
//             if(degree[i] == 0){
//                 zeroDegree.push(i);
//                 numCourses--;
//             }
//         }
        
//         while(!zeroDegree.empty()){
//             int node = zeroDegree.front();
//             zeroDegree.pop();
//             for(int i = 0; i<graph[node].size(); i++){
//                 int connectedNode = graph[node][i];
//                 degree[connectedNode]--;
//                 if(degree[connectedNode] == 0){
//                     zeroDegree.push(connectedNode);
//                     numCourses--;
//                 }
//             }
//         }
        
//         return numCourses == 0;
// } 
// };


// class Solution {
// public:
//     bool dfs(vector<vector<int>> &g, vector<int> &vis, int e, vector<int> &rec)
//     {
//         vis[e]=1;
//         rec[e]=1;
//         int count=0;
//         bool k;
//         for(int i=0;i<g[e].size();i++)
//         {
//             // if(vis[g[e][i]]) count++;
//             // if(count>=1) return false;
//             if(rec[g[e][i]]) return false;
//             if(!vis[g[e][i]])
//             {
//                 k = dfs(g, vis, g[e][i], rec);
//                 if(!k) return false;
//             }
//         }
//         rec[e]=0;
//         return true;
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int n =numCourses;
//         vector<vector<int>> g(n+1);
//         queue<int> q;
//         int a, b;
//         for(int i=0;i<prerequisites.size();i++)
//         {
//             a=prerequisites[i][0];
//             b=prerequisites[i][1];
//             g[b].push_back(a);
//             q.push(b);
//         }
//         vector<int> vis(n+1, 0);
//         int e;
//         bool k;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(!vis[i])
//             {
//                 vector<int> rec(n+1, 0);
//                 rec[i]=1;
//                 k = dfs(g, vis, i, rec);
//                 if(!k) return false;
//             }
//         }

//         return true;

//     }
// };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for(auto &i : prerequisites){
            adj[i[1]].push_back(i[0]);
            inDegree[i[0]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        int visitedNodes = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visitedNodes++;
            for(auto &i : adj[curr]){
                inDegree[i]--;
                if(inDegree[i] == 0) q.push(i);
            }
        }
        return (visitedNodes == numCourses);
    }
};
