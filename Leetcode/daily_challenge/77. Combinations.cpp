// class Solution {
// public:
//  vector<vector<int>>ans;
//  void solve(int ind,int k,vector<int>&temp,int n)
//  {
//      if(temp.size()==k)
//      {
//          ans.push_back(temp);
//          return;
//      }
//      for(int i=ind;i<n+1;i++)
//      {
//          temp.push_back(i);
//          solve(i+1,k,temp,n);
//          temp.pop_back();
//      }
//  }
//     vector<vector<int>> combine(int n, int k) 
//     {
//         vector<int>temp;
//         solve(1,k,temp,n);
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> cand(k, 0);
        int i = 0;
        while (i >= 0) {
            cand[i]++;
            if (cand[i] > n - k + i + 1) {
                i--;
            } else if (i == k-1) {
                result.push_back(cand);
            } else {
                i++;
                cand[i] = cand[i-1];
            }
        }
        return result;
    }
};
