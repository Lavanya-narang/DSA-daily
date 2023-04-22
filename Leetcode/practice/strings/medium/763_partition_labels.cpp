class Solution {
public:
//for max paritions min no of letters should be there
//all the parts should have at most 1 alphabet so one part will have max no of all occurences of a letter 
    vector<int> partitionLabels(string s) 
    {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            mp[ch]=i;
        }  
        int prev=-1,mx=0;
        for(int i=0;i<s.length();i++)
        {
            mx=max(mx,mp[s[i]]);
            if(mx==i)
            {
                ans.push_back(mx-prev);
                prev=mx;
            }
        }
        return ans;  
    }

};
