// class Solution {
// public:
//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         vector<vector<int>> memo(n, vector<int>(m, INT_MIN));
        
//         function<int(int, int)> dp = [&](int i, int j) {
//             if (i == n || j == m) {
//                 return INT_MIN;
//             }
            
//             if (memo[i][j] != INT_MIN) {
//                 return memo[i][j];
//             }
            
//             memo[i][j] = max(
//                 nums1[i] * nums2[j] + max(dp(i + 1, j + 1), 0),
//                 max(dp(i + 1, j), dp(i, j + 1))
//             );
            
//             return memo[i][j];
//         };
        
//         return dp(0, 0);
//     }
// };



class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        size_t length_a = nums1.size();
        size_t length_b = nums2.size();

        int max_product[length_a][length_b];
        max_product[0][0] = nums1[0] * nums2[0];
        for (size_t b = 1; b < length_b; b ++) {
            max_product[0][b] = std::max(
                max_product[0][b - 1],
                nums1[0] * nums2[b]
            );
        }

        for (size_t a = 1; a < length_a; a ++) {
            for (size_t b = 0; b < length_b; b ++) {
                if (b > 0) {
                    max_product[a][b] = max_product[a - 1][b - 1];
                    int current_product = nums1[a] * nums2[b];
                    if (current_product > max_product[a][b] && max_product[a][b] < 0) {
                        max_product[a][b] = current_product;
                    } else if (current_product > 0) {
                        max_product[a][b] += current_product;
                    }

                    if (max_product[a - 1][b] > max_product[a][b]) {
                        max_product[a][b] = max_product[a - 1][b];
                    }
                    if (max_product[a][b - 1] > max_product[a][b]) {
                        max_product[a][b] = max_product[a][b - 1];
                    }
                } else {
                    max_product[a][0] = std::max(
                        max_product[a - 1][0],
                        nums1[a] * nums2[0]
                    );
                }
            }
        }

        return max_product[length_a - 1][length_b - 1];
    }
};
