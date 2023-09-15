// class Solution {
// public:
//     struct node{
//         int x, y, dist;
        
//         bool operator()(node& a, node& b){
//             return a.dist > b.dist;
//         }
//     };
    
//     class UnionFind{
//         public:
//         vector<int> parent, size;
//         int edges=0;
//         UnionFind(int n){
//             parent = vector<int>(n);
//             size = vector<int>(n, 0);
//             for(int i=0; i<n; i++)
//                 parent[i]=i;
//         }
        
//         int Find(int curr){
//             int root = curr;
//             while(root != parent[root])
//                 root = parent[root];
            
//             while(curr != root){
//                 int temp = curr;
//                 curr = parent[curr];
//                 parent[curr] = root;
//             }
//             return root;
//         }
        
//         bool Union(int i, int j){
//             i = Find(i);
//             j = Find(j);
            
//             if(i == j) return false;
            
//             if(size[i] >= size[j]){
//                 size[i] += size[j];
//                 parent[j] = i;
//             }
//             else{
//                 size[j] += size[i];
//                 parent[i] = j;
//             }
            
//             edges++;
//             return true;
//         }
//     };
    
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         priority_queue<node, vector<node>, node> pq;
//         int n=points.size();
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                 pq.push({i, j, dist});
//             }
//         }
        
//         int result=0;
//         UnionFind uf(n);
        
//         while(!pq.empty()){
//             node curr = pq.top();
//             pq.pop();
            
//             if(uf.Union(curr.x, curr.y))
//                 result += curr.dist;
            
//             if(uf.edges == n-1) return result;
//         }
        
//         return 0;
//     }
// };




class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<int> dis(n,1e9),vis(n);
        int ans=0;
        dis[0]=0;
        vis[0]=1;
        int k=n-1;
        int j=0;
        while(k--){
            int mini=1e9,curr;
            for(int i=0;i<n;i++){
                dis[i]=min(dis[i],abs(p[j][0]-p[i][0])+abs(p[j][1]-p[i][1]));
                if(!vis[i] && mini>dis[i]){
                    mini=dis[i];
                    curr=i;
                }
            }
            vis[curr]=1;
            ans+=dis[curr];
            j=curr;
        }
        return ans;
    }
};
