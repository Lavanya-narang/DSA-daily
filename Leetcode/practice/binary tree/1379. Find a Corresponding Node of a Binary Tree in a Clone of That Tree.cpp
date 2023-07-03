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
// public:
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
//     {
//         TreeNode* ans;
//         if(!original)
//         {
//             return nullptr;
//         }
//         if(original==target)
//         {
//             return cloned;
//         }
//         TreeNode* left=getTargetCopy(original->left,cloned->left,target);
//         if(left)
//         {
//             return left;
//         }
//         return getTargetCopy(original->right,cloned->right,target);
//     }
// };


// class Solution {
// public:
//     TreeNode* node;
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
//         if(cloned == NULL) {
//             return cloned;
//         }
//         if(cloned->val == target->val) {
//             node = cloned;
//         }
//         getTargetCopy(original, cloned->left, target);
//         getTargetCopy(original, cloned->right, target);
//         return node;
//     }
// };



// class Solution {
// public:
//     TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
//         if (!original || !cloned)
//             return nullptr;

//         if (original->val == target->val)
//             return cloned;

//         if (TreeNode* clonedLeft = getTargetCopy(original->left, cloned->left, target))
//             return clonedLeft;

//         if (TreeNode* clonedRight = getTargetCopy(original->right, cloned->right, target))
//             return clonedRight;

//         return nullptr;
//     }
// };



class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({original, cloned});
        while(q.size()) {
            TreeNode* o1r = (q.front()).first;
            TreeNode* cl = q.front().second;
            q.pop();
            if(o1r == target) return cl;
            if(o1r -> left) q.push({o1r -> left, cl -> left});
            if(o1r -> right) q.push({o1r -> right, cl -> right});
        }
        return NULL;
    }
};
