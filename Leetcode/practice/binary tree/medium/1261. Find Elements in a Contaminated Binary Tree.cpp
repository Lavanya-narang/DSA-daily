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
class FindElements {
public:
unordered_set<int>s;
void solve(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    s.insert(root->val);
    if(root->left)
    {
        root->left->val=root->val*2+1;
    }
    if(root->right)
    {
        root->right->val=root->val*2+2;
    }
    solve(root->left);
    solve(root->right);
}
    FindElements(TreeNode* root) {
        root->val=0;
        solve(root);
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
