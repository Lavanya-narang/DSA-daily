class Solution {
public:
    void solve(string s,int i,vector<string> &op)
    {
        if(i==s.length())
        {
            op.push_back(s);
            return;
        }
       if(isalpha(s[i]))
       {
           s[i]=tolower(s[i]);
           solve(s,i+1,op);
           s[i]=toupper(s[i]);
           solve(s,i+1,op);
       }
       else
       {
           solve(s,i+1,op);
       }
    }
    vector<string> letterCasePermutation(string s) 
    {
        vector<string>op;
        solve(s,0,op);
        return op;
    }
};
