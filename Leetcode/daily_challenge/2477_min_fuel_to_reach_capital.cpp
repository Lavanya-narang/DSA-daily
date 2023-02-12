class Solution {
public:
long long totfuel;
long long dfs(int node,int par,vector<vector<int>>&v,int &seats)
{
    int ppl=1;
    for(auto child : v[node])
    {
        if(child!=par)
        {
            ppl+=dfs(child,node,v,seats);
        }
       
    }
     if(node!=0)
        {
            totfuel+=ceil((double)ppl/seats);
        }
       
     return ppl;
}

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        int n=roads.size()+1;
        vector<vector<int>>v(n);
        for(auto i: roads)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        totfuel=0;
        dfs(0,-1,v,seats);
        return totfuel;
    }
};
