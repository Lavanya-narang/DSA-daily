// class Solution {
// public:
//     long long minimumReplacement(vector<int>& nums) {
//         int n = nums.size();
//         int last = nums[n-1];  // Initialize 'last' with the last element
//         long long ans = 0;     // Initialize the total operations count

//         // Traverse the array in reverse order
//         for (int i = n - 2; i >= 0; --i) {
//             if (nums[i] > last) {  // If the current element needs replacement
//                 int t = nums[i] / last;  // Calculate how many times the element needs to be divided
//                 if (nums[i] % last) t++; // If there's a remainder, increment 't'
//                 last = nums[i] / t;  // Update 'last' for the next comparison
//                 ans += t - 1; // Add (t - 1) to 'ans' for the number of operations
//             } else {
//                 last = nums[i]; // Update 'last' without replacement
//             }
//         }
//         return ans; // Return the total number of operations
//     }

// };



class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();

        // Start from the second last element, as the last one is always sorted.
        for (int i = n - 2; i >= 0; i--) {
            // No need to break if they are already in order.
            if (nums[i] <= nums[i + 1]) {
                continue;
            }
            long long numElements = 0;
            // Count how many elements are made from breaking nums[i].
            if(nums[i]%nums[i+1] == 0) {
                numElements = nums[i]/nums[i+1];
            } else {
                numElements = nums[i]/nums[i+1] + 1;
            }
            // numElements = (nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]);

            // It requires numElements - 1 replacement operations.
            answer += numElements - 1;

            // Maximize nums[i] after replacement.
            nums[i] = nums[i] / numElements;
        }

        return answer;
    }
};
