// class Solution {
// public:
//     int equalPairs(vector<vector<int>>& grid) {
//         int ans=0,n=grid.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 bool flag=true;
//                 for(int k=0;k<n;k++)
//                 {
//                     if(grid[i][k]!=grid[k][j])
//                     {
//                         flag=false;
//                         break;
//                     }
//                 }
//                 ans+=flag;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
//  public:
//      int equalPairs(vector<vector<int>>& grid) {
//             int ans=0;
//             for(int i=0;i<grid.size();i++)
//             {
//                 vector<int>v;
//                 for(int j=0;j<grid.size();j++)
//                 {
//                     v.push_back(grid[j][i]);
//                 }
//                 ans+=count(begin(grid),end(grid),v);
//             }
//             return ans;
//           }
//  };


 class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]+=1;
        }
        
        int j=0;
        int count=0;
        for(int i=0;i<grid.size();i++){
            vector<int>column;
            for(int j=0;j<grid.size();j++){
                column.push_back(grid[j][i]);
            }
            
            if(mp.find(column)!=mp.end()){
                count+=mp[column];
            }
        }
        
        return count;
    }
};
