// class Solution {
// const int MOD = 1e9 + 7;
// public:
//     int countOrders(int n) {
//         long long count = 1;
//         for (int i = 2; i <= n; ++i) {
//             count = (count * (2 * i - 1) * i) % MOD;
//         }
//         return (int)count;
//     }
// };

class Solution {
public:
    int countOrders(int n) {
    long long res = 1, cap = 1000000007;
    for (int i=1; i<n+1; ++i) res = res * i % cap;
    for (int i=1; i<2*n; i+=2) res = res * i % cap;
    return res;
        
    }
};
