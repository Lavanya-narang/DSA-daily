
class Solution {
public:
    int answer = -1;

    void dfs(int node, vector<int>adj[], unordered_map<int, int>& time, vector<bool>& visit) {
        visit[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visit[neighbor]) {
                time[neighbor] = time[node] + 1;
                dfs(neighbor, adj, time, visit);
            } 
            else if (time.find(neighbor) != time.end()) {
                answer = max(answer, time[node] - time[neighbor] + 1);
            }
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>adj[n];
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                unordered_map<int, int> time;
                time[i] = 1;
                dfs(i, adj, time, visit);
            }
        }
        return answer;
    }
};
