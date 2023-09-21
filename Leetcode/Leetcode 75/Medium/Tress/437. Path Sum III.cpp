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
//    int ans=0;
//    int helper(TreeNode* root, int targetSum,long long curr)
//    {
//        if(root==NULL) return 0;
//        curr=curr+root->val;
//        if(curr==targetSum)
//        {
//            return 1+helper(root->left,targetSum,curr)+helper(root->right,targetSum,curr);
//        }
//        return helper(root->left,targetSum,curr)+helper(root->right,targetSum,curr);
//    }

// void dfs(TreeNode* root, int targetSum)
// {
//    if(root==NULL) return;
//        ans=ans+helper(root,targetSum,0);
//        pathSum(root->left,targetSum);
//        pathSum(root->right,targetSum);
// }


//     int pathSum(TreeNode* root, int targetSum) {
//         if(root==NULL) return 0;
//         dfs(root,targetSum);
//         return ans;
      
        
//     }
// };


class Solution {
public:
   unordered_map<long, long> map;
   int total = 0;
   int pathSum(TreeNode* root, int target) {
      map[0] = 1;
      dfs(root, 0, target);
      return total;
   }
   void dfs(TreeNode* root, long current, int target) {
      if (!root) return;
      current += root->val; // add current node to current sum
      if (map.count(current - target)) // if current - target exists in map
         total += map[current - target]; // add to total
      map[current]++; // add current to map
      dfs(root->left, current, target);
      dfs(root->right, current, target);
      map[current]--; // backtrack
   }
};
