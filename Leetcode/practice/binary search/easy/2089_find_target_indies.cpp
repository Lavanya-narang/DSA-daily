class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                ans.push_back(i);
            }
        }
            
        return ans;
    }
};



// class Solution {
// public:
// vector<int>ans;
// void bs(vector<int>& nums, int target,int low,int high)
// {
//     if(low>high)
//     {
//         return;
//     }
//     int mid=low+(high-low)/2;
//     if(nums[mid]==target)
//     {
//         bs(nums,target,low,mid-1);
//         ans.push_back(mid);
//         bs(nums,target,mid+1,high);
//     }
//     else if(nums[mid]>target)
//     {
//         bs(nums,target,low,mid-1);
//     }
//     else
//     {
//         bs(nums,target,mid+1,high);;
//     }
// }
//     vector<int> targetIndices(vector<int>& nums, int target) 
//     {
//         sort(nums.begin(),nums.end());
//         int low=0,high=nums.size()-1;
//        bs(nums,target,0,nums.size()-1);  
//         return ans;
//     }
// };
