// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        // Initialization some neccessary variables
//         vector<int>v;
        
//         // store the array in the new array
//         for(auto num:nums1)   // O(n1)
//             v.push_back(num);
        
//         for(auto num:nums2)  // O(n2)
//             v.push_back(num);
        
//         // Sort the array to find the median
//         sort(v.begin(),v.end());  // O(nlogn)
        
//         // Find the median and Return it
//         int n=v.size();  // O(n)
        
//         return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ans;
      
      int n = nums1.size();
      int m = nums2.size();

      for(int i=0;i<nums1.size();i++){
          ans.push_back(nums1[i]);
      }
      for(int i=0;i<nums2.size();i++){
          ans.push_back(nums2[i]);
      }
      sort(ans.begin(),ans.end());
     
       int size = n + m;
        if(size % 2 != 0) {
            return ans[size/2]*1.0;
        }
        else {
            double finalans = (ans[size/2] + ans[size/2-1])/2.0;
            return finalans;
        }
    }
};
