class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //iterative o(n) code
        if(!head)
        {
            return head;
        }
        ListNode *prev=nullptr,*curr=head;
        while(curr)
        {
            if(curr->val==val)
            {
                if(!prev)
                {
                    head=curr->next;
                }
                else
                {
                    prev->next=curr->next;
                }
            }
            else
            {
                prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};



class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        //recursive o(n) solution
        if(!head)
        {
            return head;
        }
         ListNode* h=removeElements(head->next,val);
         if(head->val==val)
         {
             return h;
         }
         head->next=h;
         return head;
    }
};
