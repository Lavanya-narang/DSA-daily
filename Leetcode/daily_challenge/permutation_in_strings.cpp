class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ch[26]={0};
        for(char c : s1)
        {
            ch[c - 'a']++;
        }
        int i=0,j=0,totalch=s1.size();
        while(j<s2.size())
        {
            if(ch[s2.at(j++)-'a']-- >0)
            {
                totalch--;
            }
            if(totalch==0)
            {
                return true;
            }
            if(j-i==s1.size() && ch[s2.at(i++)- 'a']++ >=0)
            {
                totalch++;
            }
        }
        return false;
    }
};
