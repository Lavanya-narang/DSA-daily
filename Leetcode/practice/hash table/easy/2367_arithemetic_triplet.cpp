// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) 
//     {
//         int n=nums.size(),ans=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     if(nums[j]-nums[i]==diff and nums[k]-nums[j]==diff)
//                     {
//                         ans++;
//                     }
//                 }
//             } 
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int arithmeticTriplets(vector<int>& nums, int diff) 
//     {
//         int ans=0,n=nums.size();
//         unordered_map<int,bool>mp;
//         for(int i=0;i<n;i++)
//         {
//             mp[nums[i]]=true;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(mp[nums[i]-diff] and mp[nums[i]+diff])
//             {
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int ans=0,n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        for(int i=0;i<n-2;i++)
        {
            int a=nums[i],b=nums[i]+diff,c=nums[i]+2*diff;
            if(s.count(b) and s.count(c))
            {
                ans++;
            }
        }
        return ans;
    }
};
