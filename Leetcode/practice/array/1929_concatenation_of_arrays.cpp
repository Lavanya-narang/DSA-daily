class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n=nums.size();
        //tc o(n) sc o(2n)
        // vector<int>ans(2*n,0);
        // for(int i=0,j=n;i<n,j<2*n;i++,j++)
        // {
        //     ans[i]=nums[i];
        //     ans[j]=nums[i];
        // }
        //tc o(n) sc o(1)
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
