//class Solution {
//public:
//     const int MOD = 1000000007;

//     int helper(const vector<int>& locations, int city, int finish, int remainFuel, vector<vector<int>>& memo) {
//         if (remainFuel < 0) {
//             return 0;
//         }
        
//         if (memo[city][remainFuel] != -1) {
//             return memo[city][remainFuel];
//         }
        
//         int total = city == finish ? 1 : 0;
        
//         for (int nextCity = 0; nextCity < locations.size(); nextCity++) {
//             if (nextCity != city && remainFuel >= abs(locations[nextCity] - locations[city])) {
//                 total = (total + helper(locations, nextCity, finish, remainFuel - abs(locations[nextCity] - locations[city]), memo)) % MOD;
//             }
//         }
        
//         return memo[city][remainFuel] = total;
//     }

//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
//         int n = locations.size();
//         vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));
//         return helper(locations, start, finish, fuel, memo);
//     }
// };


// class Solution {
// public:
//     int countRoutes(vector<int>& locations, int start, int finish, int fuel) {                
//         const int MOD = 1000000007;
//         int n = locations.size();    
        
//         vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
//         for (int f = 0; f <= fuel; f++) {
//             dp[finish][f] = 1;
//         }
        
//         // for each fuel, we calculate all cross between cities
//         for (int f = 0; f <= fuel; f++) {
//             for (int city = 0; city < n; city++) {            
//                 for (int nextCity = 0; nextCity < n; nextCity++) {               
//                     if (nextCity != city && f >= abs(locations[nextCity] - locations[city])) {
//                         dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
//                     }
//                 }
//             }            
//         }
//         return dp[start][fuel];
//     }
// };


class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size(), cost[n][n], MOD = 1e9 + 7, dp[fuel + 1][n];
        memset(cost, 0, sizeof(cost));
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                cost[i][j] = cost[j][i] = abs(locations[i] - locations[j]);

        memset(dp, 0, sizeof(dp));
        dp[0][finish] = 1;
        for (int curr_fuel = 1; curr_fuel <= fuel; curr_fuel++) {                                   
            for (int curr_start = 0; curr_start < n; curr_start++) {
                int curr_routes = 0;
                for (int next_stop = 0; next_stop < n; next_stop++) {
                    if (curr_fuel >= cost[curr_start][next_stop]) {
                        int next_fuel = curr_fuel - cost[curr_start][next_stop];
                        curr_routes = (curr_routes + dp[next_fuel][next_stop]) % MOD;
                    }
                }
                dp[curr_fuel][curr_start] = curr_routes;
            }
        }
        int routes = 0;
        for (int used_fuel = 0; used_fuel <= fuel; used_fuel++) 
            routes = (routes + dp[used_fuel][start]) % MOD;
        return routes;       
    }
};
