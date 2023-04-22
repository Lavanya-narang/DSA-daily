class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        int n=nums.size();
           vector<int>ans;
           int i=0;
           while(i<n)
           {
               for(int j=0;j<nums[i];j++)
               {
                   ans.push_back(nums[i+1]);
               }
               i=i+2;
           }
           return ans;
    }
};
