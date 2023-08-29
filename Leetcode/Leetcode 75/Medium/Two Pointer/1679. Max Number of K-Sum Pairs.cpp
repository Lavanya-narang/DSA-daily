// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 if(nums[j]==-1)
//                 {
//                     continue;
//                 }
//                 if(nums[i]+nums[j]==k)
//                 {
//                     count++;
//                     nums[i]=-1;
//                     nums[j]=-1;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };


 class Solution {
 public:
     int maxOperations(vector<int>& nums, int k)
     { 
         sort(nums.begin(),nums.end());
         int cnt=0;
         int i=0,j=nums.size()-1;
         while(i<j)
         {
             int sum=nums[i]+nums[j];
             if(sum==k)
             {
                 cnt++;
                 i++;
                 j--;
             }
             else if(sum>k)
             {
                 j--;
             }
             else 
             {
                 i++;
             }
         }
         return cnt;
     }
 };
