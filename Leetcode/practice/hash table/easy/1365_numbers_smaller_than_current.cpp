class Solution {
public:
    // vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    // {
    //     //brute force
    //     //TC:O(n^2) SC:O(n)
    //     int n=nums.size();
    //     vector<int>ans;
    //     for(int i=0;i<n;i++)
    //     {
    //         int cnt=0;
    //         for(int j=0;j<n;j++)
    //         {
    //             if(nums[i]!=nums[j] && nums[j]<nums[i])
    //             {
    //                 cnt++;
    //             }
    //         }
    //         ans.push_back(cnt);
    //     }
    //     return ans;
    // }
    //  vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    // {
    //     //TC:O(n) SC:O(n)
    //     int n=nums.size();
    //     vector<int>ans;
    //     int temp[101]={0,0,0};
    //     for(int i=0;i<n;i++)
    //     {
    //         temp[nums[i]]++;
    //     }
    //     for(int i=1;i<101;i++)
    //     {
    //         temp[i]+=temp[i-1];
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         if(nums[i]==0)
    //         {
    //             ans.push_back(0);
    //         }
    //         else
    //         {
    //             ans.push_back(temp[nums[i]-1]);
    //         }
    //     }
    //     return ans;
    // }



     vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        //TC:O(n) SC:O(n)
        int n=nums.size();
        map<int,int>mp;
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int c=0,temp;
        for(auto i:mp)
        {
            temp=i.second;
            mp[i.first]=c;
            c+=temp;
        }
        for(int i=0;i<n;i++)
        {
            res[i]=mp[nums[i]];
        }
        return res;
    }
};
