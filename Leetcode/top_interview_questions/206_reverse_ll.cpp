class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
      
      if(head==NULL || head->next==NULL)
      {
          return head;
      }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* ahead=curr->next;
        while(curr!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=ahead;
            if(curr!=NULL)
            {
                ahead=curr->next;
            }
        }
        return prev;
    }
};
