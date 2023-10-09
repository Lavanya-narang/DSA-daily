// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int startingPosition = -1, endingPosition = -1;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(nums[i] == target){
//                 startingPosition = i;
//                 break;
//             }
//         }
//         for(int i=n-1; i>=0; i--){
//             if(nums[i] == target){
//                 endingPosition = i;
//                 break;
//             }
//         }
//         return {startingPosition, endingPosition};
//     }
// };


class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r =
        upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {l, r};
  }
};
