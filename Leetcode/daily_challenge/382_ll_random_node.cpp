//reservoir sampling 
class Solution {
public:
    ListNode* headnode;
    Solution(ListNode* head) 
    {
        headnode=head;
    }
    
    int getRandom() 
    {
        int res,len=1;
        ListNode*temp=headnode;
        while(temp)
        {
            if(rand()%len==0)
            {
                res=temp->val;
            }
            len++;
            temp=temp->next;
        }
        return res;
    }
};
