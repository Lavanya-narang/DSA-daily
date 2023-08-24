// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int n = nums.size();
//         int first = INT_MAX;              
//         int second = INT_MIN;      
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] <= first)
//             {
//                 first = nums[i];
//             }
//             else if(nums[i] <= second)
//             {
//                 second = nums[i];
//             }
//             else
//                 return true;
//         }       
//         return false;
//     }
// };

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        for(int el:nums){
            if(el>mid) return true;
            else if(el>left && el<mid) mid = el;
            else if(el<left) left = el;
        }

        return false;
    }
};
