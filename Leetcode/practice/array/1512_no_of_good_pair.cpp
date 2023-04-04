class Solution {
public:
//TC:O(n2) SC:O(1)
    // int numIdenticalPairs(vector<int>& nums) 
    // {
    //     int ans=0;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(nums[i]==nums[j])
    //             {
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }


    //TC:O(nlogn) SC:O(1)
    // int numIdenticalPairs(vector<int>& nums) 
    // {
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //     int i=0,ans=0;
    //     for(int j=1;j<n;j++)
    //     {
    //         if(nums[i]==nums[j])
    //         {
    //             ans+=j-i;
    //         }
    //         else
    //         {
    //             i=j;
    //         }
    //     }
    //     return ans;
    // }

    //TC:O(n) SC:O(n)
    int numIdenticalPairs(vector<int>& nums) 
    {
        int ans=0;
        vector<int>freq(101,0);
        for(int num:nums)
        {
            ans+=freq[num]++;
        }
        return ans;
    }

};
