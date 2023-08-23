// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) 
//     {
//         int n=nums.size();
//         vector<int>answer;
//         if(n<1)
//         {
//             return answer;
//         }
//         int product=1;
//         for(int i=0;i<n;i++)
//         {
//             product*=nums[i];
//             answer.push_back(product);
//         }
//         product=1;
//         for(int i=n-1;i>0;i--)
//         {
//             answer[i]=answer[i-1]*product;
//             product*=nums[i];
//         }
//         answer[0]=product;
//         return answer;
//     }
// };


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,z,c=0;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                c++;
            }
            else
                prod*=nums[i];
        }


        for(int i=0;i<nums.size();i++)
        {

            if(c==0)
            {
                v.push_back(prod/nums[i]);
            }
            else if(c==1)
            {
                if(nums[i]==0)
                    {
                        v.push_back(prod);
                    }
                else
                    {
                        v.push_back(0); 
                    }
            }
            else if(c>1)
            {
                v.push_back(0);
            }
            
        }

        return v;


    }
};
