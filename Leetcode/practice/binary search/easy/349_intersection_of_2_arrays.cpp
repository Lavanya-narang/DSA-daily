// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//     {
//         vector<int>ans;
//         int i=0,j=0;
//         int n=nums1.size(),m=nums2.size();
//         set<int>s;
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         while(i<n && j<m)
//         {
//             if(nums1[i]>nums2[j])
//             {
//                 j++;
//             }
//            else if(nums1[i]<nums2[j])
//            {
//                i++;
//            }
//            else
//            {
//                s.insert(nums1[i]);
//                i++;
//                j++;
//            }
//         }
//         for(auto i:s)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++)
        {
            int low=0,high=nums2.size()-1,mid=0;
            while(low<=high)
            {
                mid=low+(high-low)/2;
                if(nums2[mid]==nums1[i])
                {
                    if(find(ans.begin(),ans.end(),nums2[mid])!=ans.end())
                    {
                        break;
                    }
                    ans.push_back(nums2[mid]);
                    break;
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
        return ans;
    }
};
