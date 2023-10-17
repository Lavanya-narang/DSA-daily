// class Solution {
// public:
//     bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
//         std::unordered_map<int, std::vector<int>> graph;
//         std::vector<int> in_degree(n, 0);

//         for (int node = 0; node < n; ++node) {
//             int left = leftChild[node];
//             int right = rightChild[node];
//             if (left != -1) {
//                 graph[node].push_back(left);
//                 in_degree[left]++;
//             }
//             if (right != -1) {
//                 graph[node].push_back(right);
//                 in_degree[right]++;
//             }
//         }

//         std::vector<int> root_candidates;
//         for (int node = 0; node < n; ++node) {
//             if (in_degree[node] == 0) {
//                 root_candidates.push_back(node);
//             }
//         }

//         if (root_candidates.size() != 1) {
//             return false;
//         }
//         int root = root_candidates[0];

//         std::queue<int> q;
//         std::unordered_set<int> seen;
//         q.push(root);
//         seen.insert(root);

//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             if (graph.find(node) != graph.end()) {
//                 for (int child : graph[node]) {
//                     if (seen.find(child) != seen.end()) {
//                         return false;
//                     }
//                     seen.insert(child);
//                     q.push(child);
//                 }
//             }
//         }

//         return seen.size() == n;
//     }
// };


class Solution {
public:

  bool dfs(int node, vector<int> &lc, vector<int> &rc, vector<int> &vis) {
        if(node == -1) return false;
        if(vis[node]) return true;
        vis[node] = 1;

        if(dfs(lc[node], lc, rc, vis) || dfs(rc[node], lc, rc, vis)) return true;
        return false;
    } 

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> in(n), out(n);
        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) in[leftChild[i]]++, out[i]++;
            if(rightChild[i] != -1) in[rightChild[i]]++, out[i]++;
        }

        int root = -1;
        for(int i=0; i<n; i++) {
            if(!in[i]) {
                if(root == -1) root = i;
                else return false;
            }
        }
        if(root == -1) return false;
    vector<int> vis(n);
        if(dfs(root, leftChild, rightChild, vis)) return false;

        for(int i : vis) {
            if(!i) return false;
        }
        return true;
    
    }
};
