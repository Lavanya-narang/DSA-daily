class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        //highest freq number == no of rows
        //each row has distint element keep a set for each row
        //for each row check if nums[i] is present in set or not if not add in mat if present go to next row
        
        int n=0;
        map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
            n=max(n,mp[x]);
        }
        vector<vector<int>>ans(n);
        vector<set<int>>s(n);
        for(auto x:nums)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i].find(x)==s[i].end())
                {
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;   
    }
};
