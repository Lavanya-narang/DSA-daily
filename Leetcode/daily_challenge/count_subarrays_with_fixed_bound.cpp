class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
          int n = nums.size();
        int lastInvalidElement = -1, lastMinKIdx = -1, lastMaxKIdx = -1;
        long long count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                lastMinKIdx = (nums[i] == minK) ? i : lastMinKIdx;
                lastMaxKIdx = (nums[i] == maxK) ? i : lastMaxKIdx;

                count += max(0, min(lastMinKIdx, lastMaxKIdx) - lastInvalidElement);
            } 
            else {
                lastInvalidElement = i;
                lastMinKIdx = -1;
                lastMaxKIdx = -1;
            }
        }
        
        return count;
    }
};
