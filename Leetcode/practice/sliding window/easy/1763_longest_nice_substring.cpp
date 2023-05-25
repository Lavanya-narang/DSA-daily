class Solution {
public:
    string longestNiceSubstring(string s) 
    {
        //TC:O(N) AND SC:O(1)
        if(s.size()<2)
        {
            return "";
        }
        unordered_set<char>cs;
        for(int i=0;i<s.size();i++)
        {
            cs.insert(s[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            if(cs.count(tolower(s[i]))==true and cs.count(toupper(s[i]))==true)
            {
                continue;
            }
            string prev=longestNiceSubstring(s.substr(0,i));
            string next=longestNiceSubstring(s.substr(i+1)); 
            return prev.size()>=next.size()? prev:next; 
        }
        return s;
    }
};
