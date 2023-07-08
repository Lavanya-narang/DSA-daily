// class Solution {
// public:
//     long long putMarbles(vector<int>& weights, int k) {
//         int n = weights.size();
//         if (k == 1 || n == k) return 0;
//         vector<int> candidates;
//         for (int i = 0; i < n-1; i++)
//         {
//             candidates.push_back(weights[i] + weights[i+1]);
//         }
//         sort(candidates.begin(), candidates.end());
//         long long mins = 0, maxs = 0;
//         for (int i = 0; i < k-1; i++)
//         {
//             mins += candidates[i];
//             maxs += candidates[n-2-i];
//         }
//         return maxs - mins;
//     }
// };


// Time:  O(n) on average
// Space: O(1)

// greedy, quick select
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        for (int i = 0; i + 1 < size(weights); ++i) {
            weights[i] += weights[i + 1];
        }
        weights.pop_back();
        int64_t result = 0;
        nth_element(begin(weights), begin(weights) + (k - 1), end(weights), greater<int>());
        for (int i = 0; i < k - 1; ++i) {
            result += weights[i];
        }
        nth_element(begin(weights), begin(weights) + (k - 1), end(weights));
        for (int i = 0; i < k - 1; ++i) {
            result -= weights[i];
        }
        return result;
    }
};
