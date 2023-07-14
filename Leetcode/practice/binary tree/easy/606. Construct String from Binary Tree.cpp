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
//     string tree2str(TreeNode* root) {
//         string result = "";
//         if (!root)
//             return result;

//         result += std::to_string(root->val);
//         if (root->left && !root->right) {
//             result += "(" + tree2str(root->left) + ")";
//         } else if (root->right){
//             result += "(" + tree2str(root->left) + ")";
//             result += "(" + tree2str(root->right) + ")";
//         }
           
//         return result;
//     }
// };


// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         string ans="";
//         if(root==NULL) return ans;
//         ans+=to_string(root->val);
//         if(root->left || root->right){
//             ans+="(";
//             ans+=tree2str(root->left);
//             ans+=")";
//         }
//         if(root->right){
//             ans+="(";
//             ans+=tree2str(root->right);
//             ans+=")";
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string tree2str(TreeNode* node) {
        string res = "";

        if (node == nullptr) return res;

        res += to_string(node->val);

        if (node->left || node->right) {
            res += "(";
            res += tree2str(node->left);
            res += ")";
        }
        
        if (node->right) {
            res += "(";
            res += tree2str(node->right);
            res += ")";
        }
        return res;    
    }
};
