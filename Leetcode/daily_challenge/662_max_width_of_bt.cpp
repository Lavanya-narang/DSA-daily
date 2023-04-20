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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int width=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            int mni=INT_MAX,mxi=INT_MIN;
            int startind=q.front().second;
            while(n--)
            {
                TreeNode* node=q.front().first;
                int ind=q.front().second-startind;
                q.pop();
                mxi=max(mxi,ind);
                mni=min(mni,ind);
                if(node->left)
                {
                    q.push({node->left,(long long)2*ind+1});
                }
                if(node->right)
                {
                    q.push({node->right,(long long)2*ind+2});
                }
            }
            width=max(width,mxi-mni+1);
        }  
        return width;
    }
};
