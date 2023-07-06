// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;
//         while (r < n) {
//             sum += nums[r++];
//             while (sum >= s) {
//                 len = min(len, r - l);
//                 sum -= nums[l++];
//             }
//         }
//         return len == INT_MAX ? 0 : len;
//     }
// };


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int i =0, j =0, curr_sum = nums[0], min_ans = INT_MAX;
        int size = nums.size();
        while(i<size && j<size){
            if(curr_sum<target){
                j++;
                if(j==size){
                    break;
                }
                curr_sum+=nums[j];
            }
            else{
                min_ans = min(min_ans, j-i+1);
                i++;
                if(i==size){
                    break;
                }
                curr_sum-=nums[i-1];
                
            }
        }

        if(min_ans == INT_MAX){
            return 0;
        }

        return min_ans;
    }
};
