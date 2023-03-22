class Solution {
public:
 vector<int> parent;
    vector<int> rank;
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
 
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);
 
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
 
        return parent[x];
    }
 
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
 
        // If they are already in same set
        if (xset == yset)
            return;
 
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
 
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) 
    {
        parent.resize(n,-1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        rank.resize(n,0);
        
        for(int i=0;i<roads.size();i++){
            Union(roads[i][0]-1,roads[i][1]-1);
        }
        
        int ans=INT_MAX;
        for(int i=0;i<roads.size();i++){
            if(find(roads[i][0]-1)== find(0) && find(roads[i][0]-1)==find(roads[i][1]-1)){
                ans=min(roads[i][2],ans);
            }
        }
        
        return ans;
    }
};
