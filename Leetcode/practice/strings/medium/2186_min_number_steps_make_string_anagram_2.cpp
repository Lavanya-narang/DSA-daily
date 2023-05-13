class Solution {
public:
    int minSteps(string s, string t) 
    {
        int ans=0;
        vector<int>v(26,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            v[t[i]-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            ans+=abs(v[i]);
        }
        return ans;
    }
};
