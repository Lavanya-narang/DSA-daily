
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& nums) 
//     {
//         int low=0,high=nums.size()-1;
//         while(low<=high)
//         {
//             int mid=(low+high)/2;
//             if(nums[mid]>nums[mid+1] and nums[mid-1]<nums[mid])
//             {
//                 return mid;
//             }
//             else if(nums[mid]>nums[mid+1] and nums[mid-1]>nums[mid])
//             {
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
//         }       
//         return -1;
//     }
// };




class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }else{
                e=mid;
            }

            mid=s+(e-s)/2;

        }
        return s;
        
    }
};
