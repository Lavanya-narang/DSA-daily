// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) 
//     {
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(nums[i]==nums[j] and i!=j and abs(i-j)<=k)
//                 {
//                     return true;
//                 }
//             }
//         }    
//         return false;
//     }
// };


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        if(k<n)
        {
            k=k+1;
        }
        else
        {
            k=n;
        }
        while(j<n)
        {
            mp[nums[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(mp.size()<k)
                {
                    return true;
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
                j++;
            }
        }   
        return false;
    }
};
