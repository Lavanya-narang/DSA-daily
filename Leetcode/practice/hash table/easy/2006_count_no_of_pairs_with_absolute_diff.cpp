// class Solution {
// public:
//     int countKDifference(vector<int>& nums, int k) 
//     {
//         int ans=0,n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(abs(nums[i]-nums[j])==k)
//                 {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int countKDifference(vector<int>& nums, int k) 
//     {
//         int n=nums.size(),ans=0;
//         unordered_map<int,int>mp;
//         for(auto i: nums)
//         {
//                 ans+=(mp[i+k]+mp[i-k]);
//                 mp[i]++;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
vector<int> arr(101,0);
for(int i=0;i<nums.size();i++){
    arr[nums[i]]++;
}
int ans = 0;
for(int i=k+1;i<101;i++){
 ans  += arr[i] * arr[i-k];
}
  return ans; }
};
