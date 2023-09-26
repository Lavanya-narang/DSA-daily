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
//     TreeNode* searchBST(TreeNode* root, int val) 
//     {
//         if(!root)
//         {
//             return nullptr;
//         }
//         while(root!=nullptr and root->val!=val)
//         {
//             root=(root->val>val)?root->left:root->right;
//         }
//         return root;
//     }
// };


// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         vector<int>ans;

//         if(root == NULL)
//         return NULL;
        

//         if(root->val  == val  )
//         return root;

//         if( val > root->val)
//          return searchBST(root->right,val );

//         else
//         return searchBST(root->left,val);


//     }
// };


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        else if(root->val>val) return searchBST(root->left,val);
        else if(root->val<val) return searchBST(root->right,val);
        return root;
    }
};
