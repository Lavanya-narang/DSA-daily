// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) 
//     {
//         int top=0,bottom=matrix.size()-1,right=matrix[0].size()-1,left=0,dir=0;
//         vector<int>ans;
//         int i=0;
//         while(top<=bottom && left<=right)
//         {
//             if(dir==0)
//             {
//                 for(int i=left;i<=right;i++)
//                 {
//                     ans.push_back(matrix[top][i]);
//                 }
//                 top++;
//             }
//             else if(dir==1)
//             {
//                 for(int i=top;i<=bottom;i++)
//                 {
//                     ans.push_back(matrix[i][right]);
//                 }
//                 right--;
//             }
//             else if(dir==2)
//             {
//                 for(int i=right;i>=left;i--)
//                 {
//                     ans.push_back(matrix[bottom][i]);
//                 }
//                 bottom--;
//             }
//             else if(dir==3)
//             {
//                 for(int i=bottom;i>=top;i--)
//                 {
//                     ans.push_back(matrix[i][left]);
//                 }
//                 left++;
//             }
//             dir=(dir+1)%4;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        int sr=0,sc=0,ec=n-1,er=m-1;
        vector<int>ans;
        while(sr<=er and sc<=ec)
        {
            for(int j=sc;j<=ec;j++)
            {
                ans.push_back(matrix[sr][j]);
            }
            sr++;
            for(int i=sr;i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            if(sr<=er)
            {
            for(int j=ec;j>=sc;j--)
            {
                ans.push_back(matrix[er][j]);
            }
            er--;
            }
            if(sc<=ec)
            {
            for(int i=er;i>=sr;i--)
            {
                ans.push_back(matrix[i][sc]);
            }
            sc++;
            }
        }
        return ans;
    }
};
