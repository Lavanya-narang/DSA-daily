class Solution {
public:
vector<vector<int>>ans;
void solve(vector<int>&nums,int i,int n)
{
    if(i==n)
    {
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<=n;j++)
    {
        swap(nums[i],nums[j]);
        solve(nums,i+1,n);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) 
    {
        solve(nums,0,nums.size()-1);
        return ans;
    }
};
