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
//  class bstiterator
//  {
//     stack<TreeNode*>st;
//     bool reverse=true;
//     public:
//     bstiterator(TreeNode* root,bool isreverse)
//     {
//         reverse=isreverse;
//         pushall(root);
//     }
//     bool hasnext()
//     {
//         return !st.empty();
//     }
//     int next()
//     {
//         TreeNode* n=st.top();
//         st.pop();
//         if(!reverse)
//         {
//             pushall(n->right);
//         }
//         else
//         {
//             pushall(n->left);
//         }
//         return n->val;
//     }
//     private:
//     void pushall(TreeNode* n)
//     {
//         for(;n!=nullptr;)
//         {
//             st.push(n);
//             if(reverse==true)
//             {
//                 n=n->right;
//             }
//             else
//             {
//                 n=n->left;
//             }
//         }
//     }
//  };
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) 
//     {
//         if(!root)
//         {
//             return false;
//         }
//         bstiterator l(root,false);
//         bstiterator r(root,true);
//         int i=l.next();
//         int j=r.next();
//         while(i<j)
//         {
//             if(i+j==k)
//             {
//                 return true;
//             }
//             else if(i+j>k)
//             {
//                 j=r.next();
//             }
//             else
//             {
//                 i=l.next();
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    void preorder(TreeNode* root, vector<int> &v){
        if(!root)
            return;

        v.push_back(root->val);
        preorder(root->left,v);
        preorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        preorder(root,v);
        sort(v.begin(),v.end());

        int i = 0,j = v.size()-1;
        int sum = 0;
        while(i < j){
            sum += v[i]+v[j];
            if(sum == k)
                return true;
            else if(sum > k){
                j--;
                sum = 0;
            }
            else{
                i++;
                sum = 0;
            }
        }
        return false;
    }
};
