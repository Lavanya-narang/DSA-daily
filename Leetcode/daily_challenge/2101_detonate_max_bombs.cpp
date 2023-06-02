
@deepcodes
1 hour ago
class Solution {
public:
        int maximumDetonation(vector<vector<int>>& bombs) {
		
        const int n = bombs.size();
		
        vector<int>adj[n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j){
                    int x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                    int x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                    long dist = pow(x1-x2, 2) + pow(y1-y2, 2);
                    if (dist <= (long)r1*r1) {
                       adj[i].push_back(j);
                    }
                }
            }
        }
        
        int maxDetonated = 1;
        // try each bomb and choose that which contributes maximum detonation.
        for(int i = 0; i < n; i++){
            vector<bool>detonated(n, 0);
            int currDetonated = 0;
            
			queue<int>q;
            q.push(i);
			
            while(!q.empty()) {
                int sz = q.size();
                for(int i = 0; i < sz; i++) {
                    int x = q.front();
                    q.pop();
                    detonated[x] = 1;
                    currDetonated++;
                    for(auto p : adj[x]) {
                        if(!detonated[p]) {
                            q.push(p);
                            detonated[p] = 1;
                        }
                    }
                }
            }
            maxDetonated = max(maxDetonated, currDetonated);
        }
        
        return maxDetonated;
    }
};
