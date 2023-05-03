class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int n=rowSum.size(),m=colSum.size();
        int i=0,j=0;
        vector<vector<int>>ans(n,vector<int>(m,0));
        while(i<n && j<m)
        {
            int mn=min(rowSum[i],colSum[j]);
            ans[i][j]=mn;
            rowSum[i]-=mn;
            colSum[j]-=mn;
            if(rowSum[i]==0)
            {
                i++;
            }
            if(colSum[j]==0)
            {
                j++;
            }
        }
        return ans;
    }
};
