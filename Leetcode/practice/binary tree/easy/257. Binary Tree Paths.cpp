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
// void solve(TreeNode* root,vector<string>&s,string str)
// {
//     if(!root->left and !root->right)
//     {
//         s.push_back(str);
//         return;
//     }
//     if(root->left)
//     {
//         solve(root->left,s,str+"->"+to_string(root->left->val));
//     }
//     if(root->right)
//     {
//         solve(root->right,s,str+"->"+to_string(root->right->val));
//     }
// }
//     vector<string> binaryTreePaths(TreeNode* root) 
//     {
//         vector<string>s;
//         if(!root)
//         {
//             return s;
//         }

//         solve(root,s,to_string(root->val));
//         return s;
//     }
// };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*,string>>q;
        q.push({root,to_string(root->val)});
        while(!q.empty()){
            TreeNode*curNode = q.front().first;
            string path = q.front().second;
            q.pop();
            if(!curNode->left && !curNode->right){
                ans.push_back(path);
            }
            if(curNode->left){
                string s = path+"->"+to_string(curNode->left->val);
                q.push({curNode->left,s});
            }
            if(curNode->right){
                string s = path+"->"+to_string(curNode->right->val);
                q.push({curNode->right,s});
            }
        }
        return ans;
    }
};
