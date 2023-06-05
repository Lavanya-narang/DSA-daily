class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int mp[26]={0},ans=0;
        for(auto& i: allowed)
        {
            mp[i-'a']++;
        }
        for(auto& word:words)
        {
            bool iscont=true;
            for(auto& ch:word)
            {
                if(mp[ch-'a']==0)
                {
                    iscont=false;
                    break;
                }
            }
            if(iscont)
            {
                ans++;
            }
        }
        return ans;
    }
};
