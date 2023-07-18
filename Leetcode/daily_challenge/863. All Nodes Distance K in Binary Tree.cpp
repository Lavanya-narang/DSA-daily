/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
//     void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target) {
//         queue<TreeNode*> queue;
//         queue.push(root);
//         while(!queue.empty()) { 
//             TreeNode* current = queue.front(); 
//             queue.pop();
//             if(current->left) {
//                 parent_track[current->left] = current;
//                 queue.push(current->left);
//             }
//             if(current->right) {
//                 parent_track[current->right] = current;
//                 queue.push(current->right);
//             }
//         }
//     }
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
//         markParents(root, parent_track, target); 
        
//         unordered_map<TreeNode*, bool> visited; 
//         queue<TreeNode*> queue;
//         queue.push(target);
//         visited[target] = true;
//         int curr_level = 0;
//         while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
//             int size = queue.size();
//             if(curr_level++ == k) break;
//             for(int i=0; i<size; i++) {
//                 TreeNode* current = queue.front(); queue.pop();
//                 if(current->left && !visited[current->left]) {
//                     queue.push(current->left);
//                     visited[current->left] = true;
//                 }
//                 if(current->right && !visited[current->right]) {
//                     queue.push(current->right);
//                     visited[current->right] = true;
//                 }
//                 if(parent_track[current] && !visited[parent_track[current]]) {
//                     queue.push(parent_track[current]);
//                     visited[parent_track[current]] = true;
//                 }
//             }
//         }
//         vector<int> result;
//         while(!queue.empty()) {
//             TreeNode* current = queue.front(); queue.pop();
//             result.push_back(current->val);
//         }
//         return result;
//     }
// };




class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        TreeNode* newroot = nullptr;
        findNode(root, target, nullptr, newroot);
        findK(target, k, ans);
        findK(newroot, k-1, ans);
        return ans;
    }

    bool findNode(TreeNode* root, TreeNode* target, TreeNode* prev, TreeNode*& newroot){
        if(!root)
            return false;
        if(root==target){
            newroot = prev;
            return true;
        }
        if(findNode(root->right, target, root, newroot)){
            root->right = prev;
            return true;
        }
        if(findNode(root->left, target, root, newroot)){
            root->left = prev;
            return true;
        }
        return false;
    }

    void findK(TreeNode* root, int k, vector<int>& ans){
        if(!root)
            return;
        if(k==0)
            ans.push_back(root->val);
        findK(root->left, k-1, ans);
        findK(root->right, k-1, ans);
    }
};