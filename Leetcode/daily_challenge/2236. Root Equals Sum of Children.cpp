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
//  int s=0;
//     bool checkTree(TreeNode* root) 
//     {
//         if(!root)
//         {
//             return false;
//         }
//             if(root->left)
//             {
//                 s+=root->left->val;
//             }
//             if(root->right)
//             {
//                 s+=root->right->val;
//             }
//         if(s==root->val)
//         {
//             return true;
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool checkTree(TreeNode* root) 
    {
        if(!root)
        {
            return false;
        }
        return ((root->val==root->left->val+root->right->val)?true:false);
    }
};
