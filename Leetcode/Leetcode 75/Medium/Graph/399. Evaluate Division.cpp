// class Solution {
// public:
//     unordered_map<string, vector<pair<string, double>>> adjList;
//     vector<double>ans;
//     bool dfs(string dividend, string divisor, unordered_set<string>vis, double currProd) {
//         if (vis.find(dividend) != vis.end()) {
//             return false;
//         }

//         vis.insert(dividend);
//         if (dividend == divisor) {
//             ans.push_back(currProd);
//             return true;
//         }

//         bool found = false;
//         for (auto ne : adjList[dividend]) {
//             found = dfs(ne.first, divisor, vis, currProd*ne.second);
//             if (found) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         int n = equations.size(), m = queries.size();
//         adjList.clear();
//         ans.clear();

//         for (int i = 0; i < n ; i++) {
//             string dividend = equations[i][0];
//             string divisor = equations[i][1];
//             adjList[dividend].push_back({divisor, values[i]});
//             adjList[divisor].push_back({dividend, 1.0 / values[i]});
//         }

//         for (auto &q : queries) {
//             string dividend = q[0];
//             string divisor = q[1];

//             if (adjList.find(dividend) == adjList.end() || adjList.find(divisor) == adjList.end()) {
//                 ans.push_back(-1.0);
//             }
//             else {
//                 unordered_set<string>vis;
//                 if (!dfs(dividend, divisor, vis, 1.0)) {
//                     ans.push_back(-1);
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
    void DFS(string s, string e, unordered_map<string, vector<string>>& graph, unordered_map<string, double>& umap, unordered_set<string>& visited, bool& found, double& curr) {
        if(found) return;
        visited.insert(s);
        for(auto c : graph[s]) {
            if(visited.find(c) != visited.end()) continue;
            curr *= umap[s + "/" + c];
            if(c==e) found = true;
            DFS(c, e, graph, umap, visited, found, curr);
            if(found) return;
            else curr /= umap[s + "/" + c];
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, double> umap;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> visited;
        vector<double> ans;
        int n = values.size();

        for(int i = 0; i < n; i++) {
            umap[equations[i][0] + "/" + equations[i][1]] = values[i];
            umap[equations[i][1] + "/" + equations[i][0]] = 1 / values[i];
            graph[equations[i][0]].push_back(equations[i][1]);
            graph[equations[i][1]].push_back(equations[i][0]);
        }

        
        for(auto query : queries) {
            if(graph.find(query[0]) == graph.end() || graph.find(query[1]) == graph.end()) {
                ans.push_back(-1.0);
                continue;
            }
            double curr = 1.0;
            bool found = query[0] == query[1];
            DFS(query[0], query[1], graph, umap, visited, found, curr);
            if(found) ans.push_back(curr);
            else ans.push_back(-1.0);
            visited.clear();
        }

        return ans;
    }
};
