class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            auto x=mp.find(nums2[i]);
            if(x!=mp.end() && x->second>0)
            {
                ans.push_back(nums2[i]);
                x->second--;
            }
        }
        return ans;
    }
};
