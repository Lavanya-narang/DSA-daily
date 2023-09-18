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
int solve(TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=1+solve(root->left);
    int r=1+solve(root->right);
    return max(l,r);
}
    int maxDepth(TreeNode* root) {
        return solve(root);
        // if(!root)
        // {
        //     return 0;
        // }
        // queue<TreeNode*>q;
        // int dep=0;
        // q.push(root);
        // while(!q.empty())
        // {
        //     dep++;
        //     int size=q.size();
        //     for(int i=0;i<size;i++)
        //     {
        //         TreeNode* n=q.front();
        //         q.pop();
        //         if(n->left)
        //         {
        //             q.push(n->left);
        //         }
        //         if(n->right)
        //         {
        //             q.push(n->right);
        //         }
        //     }
        // }
        // return depth;
    }

};
