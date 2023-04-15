class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        //TC:O(n) SC:O(n)
        string ans=s;
         for(int i=0;i<indices.size();i++)
         {
            ans[indices[i]]=s[i];
         }
        return ans;
       
    }
};
