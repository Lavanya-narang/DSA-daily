// class Solution {
// public:
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
//     {
//         //TC:0(NLOGN) SC:O(K)
//         vector<int>ans;
//         int m=mat.size(),n=mat[0].size();
//         int mx=INT_MAX,row=0;
//         for(int i=0;i<m;i++)
//         {
//             mat[i].push_back(i);
//         }
//         sort(mat.begin(),mat.end());
//         for(int i=0;i<k;i++)
//         {
//             ans.push_back(mat[i][n]);
//         }
//         return ans;
//     }
// };





class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n= mat.size();
        int m = mat[0].size();
        vector<int> res;
        vector<pair<int,int>> pa;
        for(int i = 0;i<n;i++)
        {
            int val = lower_bound(mat[i].begin(),mat[i].end(),0,greater<int>())-mat[i].begin();
            pa.push_back({val,i});
        }
        sort(pa.begin(),pa.end());
        for(int i=0;i<k;i++)
        {
            res.push_back(pa[i].second);
        }
        return res;

    }
};
