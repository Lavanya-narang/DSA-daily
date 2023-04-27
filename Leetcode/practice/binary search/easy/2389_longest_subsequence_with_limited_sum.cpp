class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        //tc:o(nlogn)+o(mlogn) m=no of queries
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=nums[i]+pre[i-1];
        }
        for(int i=0;i<queries.size();i++)
        {
            int query=queries[i];
            ans.push_back(upper_bound(pre.begin(),pre.end(),query)-pre.begin());//where the element u are seraching would be
        }
        return ans;
    }
};
