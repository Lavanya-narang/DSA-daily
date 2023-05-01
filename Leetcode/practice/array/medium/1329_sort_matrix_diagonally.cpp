class Solution {
public:
void solve(vector<vector<int>>&mat,int i,int j)
{
   vector<int>ans;
   int r=i,c=j;
   while(r<mat.size() && c<mat[0].size())
   {
       ans.push_back(mat[r++][c++]);
   } 
   sort(ans.begin(),ans.end());
   int k=0;
   while(i<mat.size() && j<mat[0].size())
   {
       mat[i++][j++]=ans[k++];
   } 
   
}
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
       int n=mat.size(),m=mat[0].size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               solve(mat,0,j);
           }
       } 
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               solve(mat,i,0);
           }
       }
       return mat;
    }
};
