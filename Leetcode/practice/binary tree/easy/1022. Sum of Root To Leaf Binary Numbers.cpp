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
// class Solution {
// public:
//     int sumRootToLeaf(TreeNode* root, int val = 0) {
//         if (!root) return 0;//base condition
//         //val = val << 1 | root->val; //Both are same it's just the bit manipulation way  
//         val = (val * 2 + root->val); //using Normal math
//         return (root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));//dfs call
//     }
// };


class Solution {
private:
    int preorder(TreeNode* root, int ans)
    {
        if(root == NULL)
            return 0;
        ans = ans * 2 + root -> val;
        if(root -> left == NULL && root -> right == NULL)
            return ans;
        return preorder(root -> left, ans) + preorder(root -> right, ans);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return preorder(root, 0);
    }
};
