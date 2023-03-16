class Solution {
public:
unordered_map<int,int>u;
TreeNode* build(vector<int>post,int& postind,int si,int ei)
{
    if(postind<0 || si>ei)
    {
        return nullptr;
    }
    TreeNode* root=new TreeNode(post[postind]);
    postind--;
    int rootind=u[root->val];
    root->right=build(post,postind,rootind+1,ei);
    root->left=build(post,postind,si,rootind-1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i=0;i<inorder.size();i++)
        {
            u[inorder[i]]=i;
        }
        int postind=postorder.size()-1;
        return build(postorder,postind,0,postorder.size()-1);
    }
};
