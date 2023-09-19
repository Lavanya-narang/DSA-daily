// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = nums[0];
//         int fast = nums[0];
        
//         do
//         {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         }while(slow != fast);
        
//         fast = nums[0];
//         while(slow != fast)
//         {
//             slow = nums[slow];
//             fast = nums[fast];
//         }
        
//         return slow;
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i=0;i<len;i++) {
            int idx = abs(nums[i]);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }

        return len;
    }
};
