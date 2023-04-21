class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        //TC:0(NLOGN) SC:O(K)
        vector<int>ans;
        int m=mat.size(),n=mat[0].size();
        int mx=INT_MAX,row=0;
        for(int i=0;i<m;i++)
        {
            mat[i].push_back(i);
        }
        sort(mat.begin(),mat.end());
        for(int i=0;i<k;i++)
        {
            ans.push_back(mat[i][n]);
        }
        return ans;
    }
};
