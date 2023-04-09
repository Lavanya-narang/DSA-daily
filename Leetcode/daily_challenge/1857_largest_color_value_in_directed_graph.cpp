int n=s.length();
        vector<vector<int>>g(n);
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
        }
        if(containsCycle(g,n))
            return -1;
        vector<int>indegree(n,0);
        for(auto x: edges){
            indegree[x[1]]++;
        }
        vector<vector<int>>count(n,vector<int>(26,0));
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count[i][s[i]-'a']++;   
            }
        }
        int ans=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int r=*max_element(count[p].begin(),count[p].end());
            ans=max(ans,r);
            for(auto v: g[p]){
                for(int i=0;i<26;i++){
                    count[v][i]=max(count[v][i],count[p][i]+(i==s[v]-'a'));
                }
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
