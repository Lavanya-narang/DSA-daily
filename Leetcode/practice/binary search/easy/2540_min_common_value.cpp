// class Solution {
// public:
//map approach
//     int getCommon(vector<int>& nums1, vector<int>& nums2) 
//     {
//         map<int,int>mp;
//         for(int i=0;i<nums1.size();i++)
//         {
//            mp[nums1[i]]++;
//         }
//         for(int i=0;i<nums2.size();i++)
//         {
//             if(mp.find(nums2[i])!=mp.end())
//             {
//                 return nums2[i];
//             }
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         int i=0,j=0;
//         while(i<nums1.size() && j<nums2.size()){
//             if(nums1[i] == nums2[j])
//                 return nums1[i];
//             else if(nums1[i] > nums2[j])
//                 j++;
//             else
//                 i++;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        //binary search
        for(int i=0;i<nums1.size();i++)
        {
            int low=0,high=nums2.size()-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(nums2[mid]==nums1[i])
                {
                    return nums1[i];
                }
                else if(nums2[mid]<nums1[i])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
