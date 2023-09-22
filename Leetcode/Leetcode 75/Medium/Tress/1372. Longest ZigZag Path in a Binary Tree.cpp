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
// int mx=0;
// void solve(TreeNode* root,int dir,int len)
// {
//     if(root==nullptr)
//         {
//             return;
//         }
//         mx=max(mx,len);
//         if(dir==0)
//         {
//             solve(root->left,dir,1);
//             solve(root->right,dir^1,len+1);
//         }
//         else
//         {
//             solve(root->left,dir^1,len+1);
//             solve(root->right,dir,1);
//         }
//         return;
// }
//     int longestZigZag(TreeNode* root) 
//     {
//         solve(root->left,0,1);
//         solve(root->right,1,1);
//         return mx;
//     }
// };


class Solution {
public:
    int ans=0;
    int longestZigZag(TreeNode *root){
        maxStreak(root, true, true);
        return ans;
    }

    void maxStreak(TreeNode* root, bool on_left, bool on_right, int streak=0){
        if(root->left)
            maxStreak(root->left, false, true, (streak * on_left)+1);
        else
            ans = max(ans, streak);
        root->left = nullptr;

        if(root->right)
            maxStreak(root->right, true, false, (streak * on_right)+1);
        else
            ans = max(ans, streak);
        root->right = nullptr;
    }
};
