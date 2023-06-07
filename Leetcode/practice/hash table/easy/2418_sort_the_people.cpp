class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<string>ans;
        map<int,string>mp;
        for(int i=0;i<names.size();i++)
        {
            mp[heights[i]]=names[i];
        }
        for(auto it=mp.rbegin();it!=mp.rend();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
