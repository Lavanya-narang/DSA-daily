// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int difference) {
//        unordered_map<int,int>m;
//        int mx=0;
//         for(int i=0;i<arr.size();i++){
//             int c=arr[i];
//             if(m.find(c-difference)!=m.end())
//             m[c]=m[c-difference]+1;
//             else
//             m[c]=1;
//             mx=max(mx,m[c]);
//         }
//         return mx;
//     }
// };


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int>vx(40001,0);
        int sol=1;
        for(int i=0;i<arr.size();i++)
        {
            int ke=arr[i]-difference;
            if(ke+10000<0)
            vx[arr[i]+10000]=max(1,vx[arr[i]+10000]);
            else
            {
                vx[arr[i]+10000]=max(1+vx[ke+10000],vx[arr[i]+10000]);
                sol=max(sol,vx[arr[i]+10000]);
            }

        }
        return sol;
        
    }
};
