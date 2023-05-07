/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
       vector<vector<int>>mat(m,vector<int>(n,-1));
        ListNode* curr=head;
        int sr=0,sc=0,ec=n-1,er=m-1;
        while(curr!=nullptr)
        {
            for(int j=sc;j<=ec and curr!=nullptr;j++ )
            {
                int i=sr;
                mat[i][j]=curr->val;
                curr=curr->next;
            }
            sr++;
            for(int i=sr;i<=er and curr!=nullptr;i++)
            {
                int j=ec;
                mat[i][j]=curr->val;
                curr=curr->next;
            }
            ec--;
            for(int j=ec;j>=sc and curr!=nullptr;j--)
            {
                int i=er;
                mat[i][j]=curr->val;
                curr=curr->next;
            }
            er--;
            for(int i=er;i>=sr and curr!=nullptr;i--)
            {
                int j=sc;
                mat[i][j]=curr->val;
                curr=curr->next;
            }
            sc++;
        }
        return mat;
    }
};
