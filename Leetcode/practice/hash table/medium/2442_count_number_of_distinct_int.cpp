class Solution {
public:
int reverse(int n)
{
    int ans=0;
    while(n>0)
    {
        int rem=n%10;
        n/=10;
        ans*=10;
        ans+=rem;
    }
    return ans;
}
    int countDistinctIntegers(vector<int>& nums) 
    {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};
