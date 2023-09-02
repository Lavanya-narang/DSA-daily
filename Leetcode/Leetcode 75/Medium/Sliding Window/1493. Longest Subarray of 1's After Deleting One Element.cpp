// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) 
//     {
//        int a=0,b=0,c=0;
//        for(int i=0;i<nums.size();i++)
//        {
//            if(nums[i]==1)
//            {
//                a++;
//            }
//            else
//            {
//                b=a;
//                a=0;;
//            }
//            c=max(c,b+a);
//        } 
//        if(c==nums.size())
//        {
//            return c-1;
//        }
//        else
//        {
//            return c;
//        }
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
       int n=nums.size();
       if(n==1)
       {
           return 0;
       }
       int c=0,l=0,r=0,lim=1,mlen=0;
       while(r<n)
       {
           if(nums[r]==0)
           {
               c++;
           }
           while(c>lim)
           {
               if(nums[l]==0)
               {
                   c--;
               }
               l++;
           }
           mlen=max(mlen,r-l);
           r++;
       }
       return mlen;
    }
};
