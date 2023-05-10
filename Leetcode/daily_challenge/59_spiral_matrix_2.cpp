class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int no=1;
        int sr=0,sc=0,er=n-1,ec=n-1;
        while(sr<=er and sc<=ec)
        {
            for(int j=sc;j<=ec;j++)
            {
                int i=sr;
                ans[i][j]=no++;
            }
            sr++;
            for(int i=sr;i<=er;i++)
            {
                int j=ec;
                ans[i][j]=no++;
            }
            ec--;
            for(int j=ec;j>=sc;j--)
            {
                int i=er;
                ans[i][j]=no++;
            }
            er--;
            for(int i=er;i>=sr;i--)
            {
                int j=sc;
                ans[i][j]=no++;
            }
            sc++;
        }
        return ans;
    }
};
