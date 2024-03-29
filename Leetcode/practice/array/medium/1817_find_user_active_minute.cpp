class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
       vector<int>ans(k,0);
       unordered_map<int,set<int>>mp;
       for(int i=0;i<logs.size();i++)
       {
           mp[logs[i][0]].insert(logs[i][1]);
       } 
       for(auto it=mp.begin();it!=mp.end();it++)
       {
           int idx=it->second.size()-1;
           if(idx<k)
           {
               ans[idx]++;
           }
       }
       return ans;
    }
};
