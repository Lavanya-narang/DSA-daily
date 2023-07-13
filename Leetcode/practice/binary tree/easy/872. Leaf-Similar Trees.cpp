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
void solve(TreeNode* root1,vector<int>&v)
{
    if(!root1)
    {
        return;
    }
    if(!root1->left and !root1->right)
    {
        v.push_back(root1->val);
        return;
    }
    solve(root1->left,v);
    solve(root1->right,v);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>v1,v2;
        solve(root1,v1);
        solve(root2,v2);
        if (v1.size() != v2.size()) return false;

        for (int i=0; i<v1.size(); i++){
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};
