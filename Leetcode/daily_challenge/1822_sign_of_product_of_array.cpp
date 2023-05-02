class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
       int  pro=1;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==0)
           {
               return 0;
           }
           if(nums[i]<0)
           {
               nums[i]=-1;
           }
           if(nums[i]>1)
           {
               nums[i]=1;
           }
           pro*=nums[i];
       }
       return pro;
    }
};



class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
       double  pro=1;
       for(int i=0;i<nums.size();i++)
       {
           pro*=nums[i];
       }
       if(pro<0)
       {
           return -1;
       }
       if(pro>0)
       {
           return 1;
       }
       return 0;
    }
};
