// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//     if (k == 0) return result;
//     multiset<int> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         if (i >= k)
//             w.erase(w.find(nums[i-k]));
//         w.insert(nums[i]);
//         if (i >= k-1)
//             result.push_back(*w.rbegin());
//     }
//     return result;
//     }
// };


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i=k ; i<nums.size();i++){
            if(!dq.empty() && i-dq.front()>=k){
               dq.pop_front();
            }
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
