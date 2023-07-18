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
    int sum=0;
    int F(TreeNode* root){
        if(!root) return 0;
        int x=F(root->left),y=F(root->right);
        sum+=abs(x-y);
        return root->val+x+y;
    }
    int findTilt(TreeNode* root) {
        int x=F(root);
        return sum;
    }
};
