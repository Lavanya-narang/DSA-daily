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
    
    vector<TreeNode*> generateBST(int begin, int end)
    {
        vector<TreeNode*>V;
        
        if(begin>end)
        {
            V.push_back(NULL);
            return V;
        }
        
        for(int i=begin; i<=end; i++)
        {
            vector<TreeNode*>left =  generateBST(begin, i-1);
            vector<TreeNode*>right =  generateBST(i+1,end);
            
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root = new TreeNode();
                    root->val = i;
                    root->left = l;
                    root->right = r;
                    V.push_back(root);
                }
            }
            
        }
        return V;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*>V;
        if(n==0) return V;
        
        return generateBST(1,n);
    }
};
