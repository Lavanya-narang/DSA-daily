class Solution {
 public:
     int missingNumber(vector<int>& nums) {
         int ans=0,n=nums.size();
         for(int i=0;i<n;i++)
         {
             ans^=(nums[i]^i);
         }
         ans^=n;
         return ans;
     }
 };

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) 
//     {
//         sort(nums.begin(),nums.end());
//         int low=0,high=nums.size();
//         while(low<high)
//         {
//             int mid=(high+low)/2;
//             if(nums[mid]>mid)
//             {
//                 high=mid;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }
//         return low;
//     }
// };
