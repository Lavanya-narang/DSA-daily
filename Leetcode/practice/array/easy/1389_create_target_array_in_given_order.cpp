class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        vector<int>target;
        int n=nums.size();
        int i=0;
        while(n>0)
        {
            target.insert(target.begin()+index[i],nums[i]);
            n--;
            i++;
        }
        return target;    
    }
};
