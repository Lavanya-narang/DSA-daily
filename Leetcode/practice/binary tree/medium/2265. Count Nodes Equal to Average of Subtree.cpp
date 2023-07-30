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
pair<int,int> solve(TreeNode* root,int &cnt)
{
    if(!root)
    {
        return {0,0};
    }
    auto l=solve(root->left,cnt);
    auto r=solve(root->right,cnt);
    int sum=l.first+r.first+root->val;
    int count=1+l.second+r.second;
    if(sum/count==root->val)
    {
        cnt++;
    }
    return {sum,count};
}
    int averageOfSubtree(TreeNode* root) 
    {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};
