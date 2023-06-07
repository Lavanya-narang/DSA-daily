// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
//     {
//         vector<int>ans;
//         map<int,int>mp;
//         for(int i=0;i<nums1.size();i++)
//         {
//             mp[nums1[i]]++;
//         }
//         for(int i=0;i<nums2.size();i++)
//         {
//             auto x=mp.find(nums2[i]);
//             if(x!=mp.end() && x->second>0)
//             {
//                 ans.push_back(nums2[i]);
//                 x->second--;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i =0, j= 0;
        vector<int> ans;
        int m = nums1.size(), n = nums2.size();
        while(i<m && j<n){
            //cout<<i<<" "<<j<<endl;
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        return ans;
    }
};
