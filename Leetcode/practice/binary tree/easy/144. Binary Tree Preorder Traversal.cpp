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
     vector<int> preorderTraversal(TreeNode* root) 
     {
         vector<int>ans;
        if(!root)
        {
            return ans;
       }
       stack<TreeNode*>st;
        st.push(root);
         while(!st.empty())
         {
             TreeNode* n=st.top();
             ans.push_back(n->val);
            st.pop();
             if(n->right)
             {
                 st.push(n->right);
            }
            if(n->left)
             {
                 st.push(n->left);
             }
         }
        return ans;
    }
 };


// class Solution {
// public:
//     vector<int>ans;
//     vector<int> preorderTraversal(TreeNode* root) 
//     {
//        if(!root)
//        {
//            return ans;
//        }
//        ans.push_back(root->val);
//        preorderTraversal(root->left);
//        preorderTraversal(root->right);
//         return ans;
//     }
// };
