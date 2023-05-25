// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) 
//     {
//         int m=grid.size(),n=grid[0].size(),ans=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(grid[i][j]<0)
//                 {
//                     ans++;
//                 }
//             }
//         } 
//         return ans; 
//     }
// };


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size(),ans=0;
        int low=0,high=m-1;
        while(low>=0 and low<n and high>=0 and high<m)
        {
            if(grid[low][high]<0)
            {
                ans+=(n-low);
                high--;
            }
            else
            {
                low++;
            }
        }
        return ans; 
    }
};
