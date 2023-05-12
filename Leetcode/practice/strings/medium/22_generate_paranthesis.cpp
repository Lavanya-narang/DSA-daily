class Solution {
public:
void solve(vector<string>&ans,int n,int oc,int cc,string s)
{
    if(oc==n and cc==n)
    {
        ans.push_back(s);
        return;
    }
    if(oc<n)
    {
        solve(ans,n,oc+1,cc,s+"(");
    }
    if(cc<oc)
    {
        solve(ans,n,oc,cc+1,s+")");
    }
}
    vector<string> generateParenthesis(int n) 
    {
       vector<string>ans;
       int oc=0,cc=0;
       solve(ans,n,oc,cc,"");
       return ans; 
    }
};
