// class Solution {
// public:
//     int numOfPairs(vector<string>& nums, string target) 
//     {
//         //brute force
//         int cnt=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(i!=j and nums[i]+nums[j]==target)
//                 {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        int cnt=0;
        int n=target.size();
        unordered_map<string,int>mp;
        for(auto digit:nums)
        {
            mp[digit]++;
        }
        for(int i=0;i<target.size();i++)
        {
            string s1=target.substr(0,i);
            string s2=target.substr(i,n);
            if(s1==s2)
            {
                cnt+=mp[s1]*(mp[s2]-1);
            }
            else
            {
                cnt+=mp[s1]*mp[s2];
            }
        }
        return cnt;
    }
};
