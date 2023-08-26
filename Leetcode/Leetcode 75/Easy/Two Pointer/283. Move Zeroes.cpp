// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) 
//     {
//         int n=nums.size();
//         if(n==0 || n==1)
//         {
//             return;
//         }
//         int left=0,right=0;
//         while(right<n)
//         {
//             if(nums[right]==0)
//             {
//                 right++;
//             }
//             else
//             {
//                 swap(nums[left++],nums[right++]);
//             }
//         }
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        
        while(j<n) {
            if(nums[i]==0 && nums[j]!=0) {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==0 && nums[j]==0) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }
    }
};
