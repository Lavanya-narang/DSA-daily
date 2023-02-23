class Solution {
public:
    TreeNode* treecreate(int left,int right,vector<int>& nums)
    {
        if(left==right)
        {
            return (new TreeNode(nums[left]));
        }
        if(left>right)
        {
            return NULL;
        }
        int mid=left+(right-left)/2;
        TreeNode* ptr=new TreeNode(nums[mid]);
    ptr->left=treecreate(left,mid-1,nums);
    ptr->right=treecreate(mid+1,right,nums);
    return ptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        return treecreate(left,right,nums);
    }
};
