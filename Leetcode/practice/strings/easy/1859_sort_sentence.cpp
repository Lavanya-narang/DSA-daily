class Solution {
public:
    string sortSentence(string s) 
    {
        string ans;
        string word;
        vector<string>v(10);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                v[s[i]-48]=word +" ";
                word="";
                i++;
            }
            else
            {
                word +=s[i];
            }
        }
        for(string x: v)
        {
            ans+=x;
        }
        ans.pop_back();
        return ans;  
    }
};
