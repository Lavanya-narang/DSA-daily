// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) 
//     {
//         int ans=0,sum=0,n=nums.size();
//         map<int,int>mp;
//         mp[0]=1;
//         for(int i=0;i<n;i++)
//         {
//             sum+=nums[i]%2;
//             if(mp.find(sum-k)!=mp.end())
//             {
//                 ans+=mp[sum-k];
//             }
//             mp[sum]++;
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int subArray(vector<int>& nums, int k) {
//         int count = 0, ans = 0, i = 0, j = 0;
//         int n = nums.size();
//         while(j<n){
//             if(nums[j]%2==1){
//                 count++;
//             }
//             while(count>k){
//                 if(nums[i]%2==1){
//                     count--;
//                 }
//                 i++;
//             }
//             ans += j-i+1;
//             j++;
//         }
//         return ans;
//     }
//     int numberOfSubarrays(vector<int>& nums, int k) {
//       return subArray(nums, k) - subArray(nums, k - 1);
//     }
// };

class Solution {
 public:
     int numberOfSubarrays(vector<int>& nums, int k) 
     {
int i=0,j=0,ans=0,odc=0,c=0;
while(j<nums.size())
{
    if(nums[j]%2!=0)
    {
        odc++;
        ans=0;
    }
    while(odc==k)
    {
        ans++;
        if(nums[i]%2!=0)
        {
            odc--;
        }
        i++;
    }
    c+=ans;
    j++;
}
return c;
    }
};
