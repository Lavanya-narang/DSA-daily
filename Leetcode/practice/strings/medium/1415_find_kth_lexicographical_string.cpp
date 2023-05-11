class Solution {
public:
void solve(int n,string s,vector<string>&ans)
{
    if(n==0)
    {
        ans.push_back(s);
        return;
    }
    if(s.back()!='a')
    {
        solve(n-1,s+'a',ans);
    }
    if(s.back()!='b')
    {
        solve(n-1,s+'b',ans);
    }
    if(s.back()!='c')
    {
        solve(n-1,s+'c',ans);
    }

}
    string getHappyString(int n, int k) 
    {
       vector<string>ans;
       solve(n,"",ans);
       if(k>ans.size())
       {
           return "";
       } 
       return ans[--k];
    }
};
