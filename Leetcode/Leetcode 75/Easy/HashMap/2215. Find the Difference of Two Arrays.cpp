// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
//     {
//         vector<vector<int>>ans(2);
//         unordered_set<int>s1(nums1.begin(),nums1.end());
//         unordered_set<int>s2(nums2.begin(),nums2.end());
//         for(auto it:s1)
//         {
//             if(s2.count(it)==0)
//             {
//                 ans[0].push_back(it);
//             }
//         }
//          for(auto it:s2)
//         {
//             if(s1.count(it)==0)
//             {
//                 ans[1].push_back(it);
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n= nums2.size();
        int arr[2001]={0};
        vector<vector<int>> answer(2);
        for(int i=0;i<m;i++){
            arr[nums1[i]+1000]+=10;
        }
        for(int i=0;i<n;i++){
            arr[nums2[i]+1000]--;
        }
        for(int i=0;i<2001;i++){
            if(arr[i]%10==0&&arr[i]!=0){
                answer[0].push_back(i-1000);
            }
            if(arr[i]<0){
                answer[1].push_back(i-1000);
            }
        }
        return answer;
    }
};
