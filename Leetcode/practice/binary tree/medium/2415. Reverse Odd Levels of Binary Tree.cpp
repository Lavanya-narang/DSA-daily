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
//     TreeNode* reverseOddLevels(TreeNode* root) 
//     {
//        if(!root)
//        {
//            return root;
//        } 
//        int flag=0;
//        vector<int>ans;
//        queue<TreeNode*>q;
//        q.push(root);
//        while(!q.empty())
//        {
//            int size=q.size();
//            vector<int>level;
//            for(int i=0;i<size;i++)
//            {
//                TreeNode* n=q.front();
//                q.pop();
//                 if(flag%2)
//                 {
//                     n->val=ans[size-i-1];
//                 }
//                 if(n->left)
//                 {
//                     q.push(n->left);
//                     level.push_back(n->left->val);
//                 }
//                 if(n->right)
//                 {
//                     q.push(n->right);
//                     level.push_back(n->right->val);
//                 }
//            }
//            ans=level;
//            flag++;
//        }
//        return root;
//     }
// };



class Solution {
public:
    void preorder(TreeNode* left, TreeNode* right, int depth) {
        if (!left || !right)
            return;

        depth++;

        if (depth % 2) {
            swap(right->val, left->val);
        }

        preorder(left->left, right->right, depth);
        preorder(left->right, right->left, depth);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        preorder(root->left, root->right,0);
        return root;
    }
};
