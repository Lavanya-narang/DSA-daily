// class SegmentTree
// {
//     public:
//     vector<int> tree;
//     int n;
//     SegmentTree(int n)
//     {
//         int x=ceil(log2(n));
//         int max_size=2*(int)pow(2,x)-1;
//         this->n=max_size;
//         this->tree.resize(max_size);
//     }
//     int query(int ql,int qr,int cl,int cr,int node){
//         if(cl>=ql && cr<=qr){
//             return tree[node];
//         }
//         if(cr<ql||cl>qr){
//             return 0;
//         }
//         int mid=(cl+cr)/2;
//         int x=query(ql,qr,cl,mid,2*node+1),y=query(ql,qr,mid+1,cr,2*node+2);
//         return max(x,y);
//     }
//     void update(int idx,int val, int cl,int cr,int pos){
//         if(pos<cl||pos>cr)return;
        
//         if(cl==cr){
//             tree[idx]=val;
//             return;
//         }
//         int mid=(cl+cr)/2;
//         update(2*idx+1,val,cl,mid,pos);
//         update(2*idx+2,val,mid+1,cr,pos);
//         tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
//     }
// };
// class Solution {
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//         SegmentTree t(nums.size());
    
//         for(int i=0;i<nums.size();i++){
//             int left=max(0,i-k),right=max(0,i-1);
//             int x=t.query(left,right,0,nums.size()-1,0);
//             t.update(0,nums[i]+x,0,nums.size()-1,i);
//         }
//         return t.tree[0];
//     }
// };



class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> sum_to_i = nums;
        deque<int> q;

        for (int i = 0; i < sum_to_i.size(); i++) {
            if (!q.empty()) sum_to_i[i] += q.front();

            while (!q.empty() && q.back() < sum_to_i[i]) {
                q.pop_back();
            }

            if (sum_to_i[i] > 0) q.push_back(sum_to_i[i]);

            if (i >= k && q.front() == sum_to_i[i - k]) {
                q.pop_front();
            }
        }
        return *max_element(sum_to_i.begin(), sum_to_i.end());
    }
};
