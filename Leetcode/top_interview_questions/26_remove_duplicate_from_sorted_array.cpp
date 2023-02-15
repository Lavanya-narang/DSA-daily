class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        vector<int>:: iterator i;
        for(i=nums.begin();i!=nums.end();i++)
        {
            int ele=*i;
            if(find(ans.begin(),ans.end(),ele)!=ans.end())
            {
                nums.erase(i);
                i--;
            }
            else
            {
                ans.push_back(*i);
            }
        }
        return nums.size();
    }
};
