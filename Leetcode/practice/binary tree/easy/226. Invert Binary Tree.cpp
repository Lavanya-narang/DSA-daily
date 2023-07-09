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
// void solve( TreeNode* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     TreeNode* temp=root->left;
//     root->left=root->right;
//     root->right=temp;
//     solve(root->left);
//     solve(root->right);
// }
//     TreeNode* invertTree(TreeNode* root) {
//         //  if(!root)
//         // {
//         //     return root;
//         // }
//         // queue<TreeNode*>q;
//         // q.push(root);
//         // while(!q.empty())
//         // {
//         //     TreeNode* curr=q.front();
//         //     q.pop();
//         //     TreeNode* temp=curr->left;
//         //     curr->left=curr->right;
//         //     curr->right=temp;
//         //     if(curr->left)
//         //     {
//         //         q.push(curr->left);
//         //     }
//         //     if(curr->right)
//         //     {
//         //         q.push(curr->right);
//         //     }
//         // }
//         // solve(root);
//         // return root;
//     }
// };


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        while (!q.empty()) {
            swap(cur->left, cur->right);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            q.pop();
            cur = q.front();
        }
        return root;
    }
};
