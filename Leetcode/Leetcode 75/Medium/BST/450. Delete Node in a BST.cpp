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
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root) 
//             if(key < root->val) root->left = deleteNode(root->left, key);     //We frecursively call the function until we find the target node
//             else if(key > root->val) root->right = deleteNode(root->right, key);       
//             else{
//                 if(!root->left && !root->right) return NULL;          //No child condition
//                 if (!root->left || !root->right)
//                     return root->left ? root->left : root->right;    //One child contion -> replace the node with it's child
// 					                                                //Two child condition   
//                 TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
//                 while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
//                 root->val = temp->val;                            //       root->val = temp->val;
//                 root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);		
//             }
//         return root;
//     }   
// };


class Solution {
public:
    TreeNode* minval(TreeNode* root){
        TreeNode*  curr =root;
        while(curr->left!=NULL){
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL ;
        }
        if(root->val == key){
            if(root->left==NULL && root->right ==NULL){
                delete root;
                return NULL;
            }
            if(root->left!=NULL && root->right ==NULL){
                TreeNode* leftans = root->left;
                delete root;
                return leftans;
            }
            if(root->left==NULL && root->right !=NULL){
                TreeNode* rightans = root->right;
                delete root;
                return rightans;
            }
            if(root->left!=NULL && root->right !=NULL){     
                int mini = minval(root->right)->val;
                root->val =mini;
                root->right = deleteNode(root->right,mini);
                return root;

            }
        }
        else if(root->val>key){
            root->left= deleteNode(root->left,key);
            return root;
        }
        else{
            root->right= deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};
