class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mmp{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int val=0;
        for(int i=0;i<s.length();i++)
        {
            if(mmp[s[i]]<mmp[s[i+1]])
            {
                val-=mmp[s[i]];
            }
            else
            {
                val+=mmp[s[i]];
            }
        }
        return val;
    }
};
