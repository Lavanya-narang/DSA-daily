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
// void solve(TreeNode* root, int low, int high,int &sum)
// {
//     if(!root)
//     {
//         return;
//     }
//     if(root->val>=low and root->val<=high)
//     {
//         sum+=root->val;
//     }
//     solve(root->left,low,high,sum);
//     solve(root->right,low,high,sum);
// }
//     int rangeSumBST(TreeNode* root, int low, int high) 
//     {
//         int sum=0;
//         solve(root,low,high,sum);
//         return sum;
//     }
// };


// class Solution {
// public:
// int sum=0;
//     int rangeSumBST(TreeNode* root, int low, int high) 
//     {
        
//         if(root==0)
//         {
//             return sum;
//         }
//             if(root->val>=low and root->val<=high)
//             {
//                 sum+=root->val;
//             }
//                 rangeSumBST(root->left,low,high);
//                 rangeSumBST(root->right,low,high);
//         return sum;
//     }
// };




class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return 0;

        if(root->val < low) root->left = nullptr;
        if(root->val > high) root->right = nullptr;

        return (root->val >= low && root->val <= high ? root->val : 0) +rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};
