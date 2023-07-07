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
    TreeNode* increasingBST(TreeNode* root) 
    {
        stack<TreeNode*>st;
        TreeNode* head=new TreeNode(0),*pre=head;
        while(!st.empty() || root)
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
                    pre->right=root;
                    pre=pre->right;
                    root->left=nullptr;
                    root=root->right;
        }
        return head->right;
    }
};
