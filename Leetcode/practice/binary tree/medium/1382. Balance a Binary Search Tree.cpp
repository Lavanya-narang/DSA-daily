/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<TreeNode*>ans;
void inorder(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    inorder(root->left);
    ans.push_back(root);
    inorder(root->right);
}
TreeNode* solve(int l,int r)
{
    if(l>r)
    {
        return nullptr;
    }
    int m=(l+r)/2;
    ans[m]->left=solve(l,m-1);
    ans[m]->right=solve(m+1,r);
    return ans[m];
}
    TreeNode* balanceBST(TreeNode* root) 
    {
       inorder(root);
       return solve(0,ans.size()-1); 
    }
};
