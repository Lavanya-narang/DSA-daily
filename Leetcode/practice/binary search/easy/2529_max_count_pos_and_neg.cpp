// class Solution {
// public:
//     int maximumCount(vector<int>& nums) 
//     {
//         int pos=0,neg=0;
//         for(auto n:nums)
//         {
//             if(n>0)
//             {
//                 pos++;
//             }
//             if(n<0)
//             {
//                 neg++;
//             }
//         }
//         if(neg>pos)
//         {
//             return neg;
//         }
//         return pos;
//     }
// };


class Solution {
public:
    int maximumCount(vector<int>& nums) 
    {
        int pos=0,neg=0;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(high+low)/2;
            if(nums[mid]>0)
            {
                pos+=(high-mid)+1;
                high=mid-1;
            }
            else if(nums[mid]<0)
            {
                neg+=(mid-low)+1;
                low=mid+1;
            }
            else
            {
                int k=mid;
                while(k-1>=0 and nums[k-1]==0)
                {
                    k--;
                }
                neg+=(k-low);
                k=mid;
                while(k<high and nums[k+1]==0)
                {
                    k++;
                }
                pos+=(high-k);
                break;
            }
        }
        return pos>neg?pos:neg;
    }
};
