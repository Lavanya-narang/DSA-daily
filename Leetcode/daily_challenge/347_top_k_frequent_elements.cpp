class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        multimap<int,int>mm;
        for(auto it:mp)
            mm.insert({it.second,it.first});
        for(auto it=mm.rbegin();it!=mm.rend();it++){
            if(k==0)
                break;
            ans.push_back(it->second);
            k--;
        }
        return ans;
    }
};
