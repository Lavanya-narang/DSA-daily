class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        int temp=(2*k)+1;
        if(n<temp)
        {
            return ans;
        }
        if(k==0)
        {
            return nums;
        }
        long long int i=0,s=0,avg=0;
        int j=0;
        for(int j=0;j<n;j++)
        {
            s+=nums[j];
            if((j-i+1)==temp)
            {
                avg=s/temp;
                ans[j-k]=avg;
                s-=nums[i];
                i++;
            }
        }
        return ans;
    }
};
